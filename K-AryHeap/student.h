#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "priority_queue.h"
#include <iostream>
#include<math.h>


template <typename T,typename Comp >
void CP::priority_queue<T,Comp>::fixUp(size_t idx) {
    T ref = mData[idx];
    while(idx > 0){
        if(mLess(mData[idx], mData[(idx-1)/4])){
            break;
        }
        std::swap(mData[(idx-1)/4],mData[idx]);
        idx = (idx-1)/4;
    }
    mData[idx] = ref;
}

template <typename T,typename Comp >
void CP::priority_queue<T,Comp>::fixDown(size_t idx) {
    while((4*idx)+1 < mSize){
        size_t midx = 0;
        for(int i = 0; (i < 4) && (4*idx+1+i < mSize); i++){
            if(!mLess(mData[4*idx+1+i],mData[(4*idx)+1+midx])){
                midx = i;
            }
        }
        if(!mLess(mData[idx], mData[(4*idx)+1+midx])){
            break;
        }
        std::swap(mData[idx], mData[(4*idx)+1+midx]);
        idx = (4*idx)+1+midx;
    }
}

#endif

