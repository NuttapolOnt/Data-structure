#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
CP::list<T> CP::list<T>::split(iterator it,size_t pos) {
  //write your code here
  CP::list<T> result;
  if(it != mHeader -> prev){
    iterator itref1 = it.ptr -> prev;
    iterator itref2 = mHeader -> prev;
    itref1.ptr -> next = mHeader;
    mHeader -> prev = itref1.ptr;
    result.mHeader -> next = it.ptr;
    it.ptr -> prev = result.mHeader;
    result.mHeader -> prev = itref2.ptr;
    itref2.ptr -> next = result.mHeader;
    result.mSize = mSize - pos;
    mSize = pos;
  }
  return result;
}

#endif
