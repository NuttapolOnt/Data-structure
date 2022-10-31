#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
std::vector<T> CP::queue<T>::to_vector(int k) const {
  std::vector<T> res;
  //write your code only here//
  for(int i = 0; i < k; i++){
    res.push_back(mData[(mFront + i) % mCap]);
  }
  return res;
}

template <typename T>
CP::queue<T>::queue(iterator from,iterator to) {
  //write your code only here
  T *ans = new T[to - from]();
  for(int i = 0; i < to - from; i++){
    ans[i] = *(from + i);
  }
  mData = i;
  mSize = to - from;
  mCap = mSize;
  mFront = 0;
}

#endif
