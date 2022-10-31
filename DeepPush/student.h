#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::stack<T>::deep_push(size_t pos,const T& value) {
  //write your code here
  T *ans = new T[mSize + 1]();
  int count = 0;
  int n = mSize - pos;
  for(int i = 0; i < (mSize +1); i++){
    if (i == n){
      ans[i] = value;
      count++;
    }
    else{
      ans[i] = mData[i- count];
    }
  }

  mData = ans;
  mSize++;
  mCap = mSize;
}

#endif
