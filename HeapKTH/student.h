#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "priority_queue.h"

template <typename T,typename Comp >
T CP::priority_queue<T,Comp>::get_kth(size_t k) const {
  //write your code here
  //can include anything
  std::vector<T> ans;
  if(mSize <= 14){
    for(int i = 0; i < mSize; i++){
      ans.push_back(mData[i]);
    }
  }
  else{
    ans.push_back(mData[0]);
    ans.push_back(mData[1]);
    ans.push_back(mData[2]);
    ans.push_back(mData[mSize -1]);
    ans.push_back(mData[mSize -2]);
    if(mLess(mData[1], mData[2])){
      if(mLess(mData[3],mData[4])){
        ans.push_back(mData[3]);
        if(mLess(mData[7],mData[8])){
          ans.push_back(mData[7]);
        }
        else{
          ans.push_back(mData[8]);
        }
      }
      else{
        ans.push_back(mData[4]);
        if(mLess(mData[9],mData[10])){
          ans.push_back(mData[9]);
        }
        else{
          ans.push_back(mData[10]);
        }
      }
    }
    else{
      if(mLess(mData[5],mData[6])){
        ans.push_back(mData[5]);
        if(mLess(mData[11],mData[12])){
          ans.push_back(mData[11]);
        }
        else{
          ans.push_back(mData[12]);
        }
      }
      else{
        ans.push_back(mData[6]);
        if(mLess(mData[13],mData[14])){
          ans.push_back(mData[13]);
        }
        else{
          ans.push_back(mData[14]);
        }
      }
    }
  }
  sort(ans.begin(), ans.end(),mLess);
  return ans[ans.size() -k];
}

#endif
