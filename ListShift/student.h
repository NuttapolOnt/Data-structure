#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
void CP::list<T>::shift_left() {
  // your code here
  iterator itref = begin();
  begin().ptr -> next -> prev = mHeader;
  mHeader -> next = begin().ptr -> next;
  mHeader -> prev -> next = itref.ptr;
  itref.ptr -> prev = mHeader -> prev;
  mHeader -> prev = itref.ptr;
  itref.ptr -> next = mHeader;
  
}

#endif
