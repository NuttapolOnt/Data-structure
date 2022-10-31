#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "map_bst.h"

template <typename KeyT,typename MappedT, typename CompareT >
size_t CP::map_bst<KeyT,MappedT,CompareT>::process(node* n) {
  //write your code here
  if(n == NULL){
    return 0;
  }
  else{
    return 1 + process(n -> right) + process(n -> left); 
  }
}

template <typename KeyT,typename MappedT, typename CompareT >
std::pair<KeyT,MappedT> CP::map_bst<KeyT,MappedT,CompareT>::subtree(map_bst<KeyT,MappedT,CompareT> &left, map_bst<KeyT,MappedT,CompareT> &right) {
  //write your code here
  if (mSize == 0){
    return std::pair<KeyT,MappedT>();
  }
  else if(mSize == 1){
    return mRoot -> data;
  }
  if(mRoot -> left != NULL){
    left.clear();
    left.mRoot = mRoot -> left;
    left.mRoot -> parent = NULL;
    int n = process(mRoot -> left);
    left.mSize = n;
    mRoot -> left = NULL;
    mSize -= n;
  }
  if(mRoot -> right != NULL){
    right.clear();
    right.mRoot = mRoot -> right;
    right.mRoot -> parent = NULL;
    int n = process(mRoot -> right);
    right.mSize = n;
    mRoot -> right = NULL;
    mSize -= n;
  }
  return mRoot -> data;
}

#endif

