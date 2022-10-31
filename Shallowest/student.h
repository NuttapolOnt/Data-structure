#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>
#include<vector>

//you can use this function
template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT,MappedT,CompareT>::shallowest_leaf(node* n) {
  if((n -> left != NULL) && (n -> right != NULL)){
    int a = shallowest_leaf(n -> left);
    int b = shallowest_leaf(n -> right);
    if(b < a){
      return b+1;
    }
    return a+1;
  }
  else if((n -> left != NULL) && (n -> right == NULL)){
    return 1 + shallowest_leaf(n -> left);
  }
  else if((n -> left == NULL) && (n -> right != NULL)){
    return 1 + shallowest_leaf(n -> right);
  }
  else if ((n -> left == NULL) && (n -> right == NULL)){
    return 0;
  }
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT,MappedT,CompareT>::shallowest_leaf() {
  //write your code here
  std::vector<int> ans;
  if(mSize == 0){
    return -1;
  }
  else if((mRoot -> left != NULL) && (mRoot -> right != NULL)){
    int a = shallowest_leaf(mRoot -> left);
    int b = shallowest_leaf(mRoot -> right);
    if(b < a){
      return b+1;
    }
    return a+1;
  }
  else if((mRoot -> left != NULL) && (mRoot -> right == NULL)){
    return 1 + shallowest_leaf(mRoot -> left);
  }
  else if((mRoot -> left == NULL) && (mRoot -> right != NULL)){
    return 1 + shallowest_leaf(mRoot -> right);
  }
  else if ((mRoot -> left == NULL) && (mRoot -> right == NULL)){
    return 0;
  }
}



#endif
