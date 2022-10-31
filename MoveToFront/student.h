#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

template <typename T>
void CP::queue<T>::move_to_front(size_t pos) {
    //your code here
    T *ans = new T[mSize]();
    ans[0] = mData[(mFront + pos) % mCap];
    int count = -1;
    for(int i = 1; i < mSize; i++){
        if(i -1 == pos){
            count++;
        }
        ans[i] = mData[(mFront + i + count) % mCap];
    }
    mFront = 0;
    delete [] mData;
    mData = ans;
    mCap = mSize;
}

#endif
