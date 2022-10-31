#ifndef __STUDENT_H_
#define __STUDENT_H_
#include<unordered_set>
//you can include any other file here
//you are allow to use any data structure


template <typename T>
void CP::vector<T>::uniq() {
  //do someting here
  std::unordered_set<T> us;
  int count = 0;
  for(int i = 0; i < mSize; i++){
    T n = mData[i];
    if(us.find(n) == us.end()){
      us.insert(n);
      mData[count] = mData[i];
      count+=1;
    }
  }
  resize(count);
}

#endif
