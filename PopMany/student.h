#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::stack<T>::multi_pop(size_t K) {
  //write your code here
  if(K >= mSize){
    K = mSize;
  }
  for(int i = 0; i < K; i++){
    pop();
  }
}

template <typename T>
std::stack<T> CP::stack<T>::remove_top(size_t K) {
  //write your code here
  //
  //don't forget to return an std::stack
  std::stack<T> ans;
  if(K >= mSize){
    for(int i = 0; i<mSize; i++){
      ans.push(mData[i]);
    }
    multi_pop(K);
  }
  else{
    for(int i = mSize - K; i < mSize; i++){
      ans.push(mData[i]);
    }
    multi_pop(K);
  }
  return ans;
}

#endif
