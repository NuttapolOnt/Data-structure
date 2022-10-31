#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
typename CP::list<T>::iterator CP::list<T>::reverse(iterator a, iterator b) {
  //write your code here
  iterator itcheck = a.ptr->prev;
  iterator itref = a.ptr -> prev;
  iterator it = b.ptr -> prev;
  while(it != itcheck){
    iterator tmp = it.ptr -> prev;
    itref.ptr -> next = it.ptr;
    it.ptr -> prev = itref.ptr;
    itref = it.ptr;
    it = tmp;
  }
  b.ptr -> prev = itref.ptr;
  itref.ptr -> next = b.ptr;
  return it.ptr -> next;
}

#endif
