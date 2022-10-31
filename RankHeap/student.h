#ifndef __STUDENT_H_
#define __STUDENT_H_

#include<algorithm>

using namespace std;

template <typename T,typename Comp>
size_t CP::priority_queue<T,Comp>::get_rank(size_t pos) const {
  //write your code here
  int count = 0;
  T ref = mData[pos];
  for(int i = 0; i < mSize; i++){
    if(mLess(ref,mData[i])){
      count++;
    }
  }
  return count;
}

#endif
