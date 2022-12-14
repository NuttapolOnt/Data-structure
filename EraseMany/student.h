#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos) {
  //write your code here
  bool *ref = new bool[mSize]();
  for(int x : pos){
    ref[x] = true;
  }
  int count = 0;
  for(int i = 0; i < size() ; i++){
    if(!ref[i]){
      mData[count] = mData[i];
      count += 1;
    }
  }
  resize(count);
}

#endif
