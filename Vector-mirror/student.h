#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::mirror() {
  //write your code here
  T ans[mSize*2];
  for(int i = 0; i < mSize; i++){
    ans[i] = *(mData+i);
  }
  int count = (mSize-1);
  for(int j = mSize; j < mSize*2; j++){
    ans[j] = *(mData + count);
    count -= 1;
  }
  delete [] mData;
  mData = ans;
  mSize = mSize*2;
  mCap = mSize*2;
}
#endif