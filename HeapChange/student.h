#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <assert.h>

template <typename T,typename Comp>
void CP::priority_queue<T,Comp>::change_value(size_t pos,const T& value) {
  //write your code here
  mData[pos] = value;
  if(pos == 0){
    fixDown(pos);
  }
  else if(mLess(value, mData[(pos-1)/2])){
    fixDown(pos);
  }
  else if(!(mLess(value, mData[pos*2+1]) || mLess(value, mData[pos*2+2]))){
    fixUp(pos);
  }
}

#endif
