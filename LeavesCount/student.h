#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

// you can modify and use this function
template <typename KeyT,
          typename MappedT,
          typename CompareT>
size_t CP::map_bst<KeyT,MappedT,CompareT>::leaves_count(node* n) {
  if((n -> left != NULL) && (n -> right != NULL)){
    return leaves_count(n -> left) + leaves_count(n -> right);
  }
  else if((n -> left != NULL) && (n -> right == NULL)){
    return leaves_count(n -> left);
  }
  else if((n -> left == NULL) && (n -> right != NULL)){
    return leaves_count(n -> right);
  }
  else if((n -> left == NULL) && (n -> right == NULL)){
    return 1;
  }
}


template <typename KeyT,
          typename MappedT,
          typename CompareT>
size_t CP::map_bst<KeyT,MappedT,CompareT>::leaves_count() {
  //write your code here
  if(mSize == 0){
    return 0;
  }
  else if((mRoot -> left != NULL) && (mRoot -> right != NULL)){
    return leaves_count(mRoot -> left) + leaves_count(mRoot -> right);
  }
  else if((mRoot -> left != NULL) && (mRoot -> right == NULL)){
    return leaves_count(mRoot -> left);
  }
  else if((mRoot -> left == NULL) && (mRoot -> right != NULL)){
    return leaves_count(mRoot -> right);
  }
  else if((mRoot -> left == NULL) && (mRoot -> right == NULL)){
    return 1;
  }
}


#endif
