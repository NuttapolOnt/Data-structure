#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename KeyT,
          typename MappedT,
          typename CompareT>
size_t CP::map_bst<KeyT,MappedT,CompareT>::process(node* ptr) const {
  //you may write additional code here
  if((ptr -> left == NULL) && (ptr -> right != NULL)) {
    return 1 + process(ptr -> right);
  }
  else if((ptr -> left != NULL) && (ptr -> right == NULL)){
    return 1 + process(ptr -> left);
  }
  else if ((ptr -> left != NULL) && (ptr -> right != NULL)){
    return process(ptr -> right) + process(ptr -> left);
  }
  return 0;
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
size_t CP::map_bst<KeyT,MappedT,CompareT>::count_unary() const {
  //write your code here
  return process(mRoot);
}

#endif
