#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

template <typename T>
void CP::queue<T>::back_to_front() {
  //write your code here
  if(size() != 0){
    T ref = mData[(mFront + mSize -1) % mCap];
    mFront = (mFront - 1 + mCap) % mCap;
    mData[mFront] = ref;
  }
}

#endif