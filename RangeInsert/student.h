#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::insert(iterator position,iterator first,iterator last) {
  //write your code here
  int n = mSize-(position-mData);
  T *ref = new T[n]();
  int count = 0;
  for(auto it = position; it != end(); it++,count++ ){
    ref[count] = *it;
  }
  int pos = position - begin();
  resize(mSize + (last-first));
  position = begin()+pos;
  for(int i = 0; i < (last-first); i++){
    *(position + i) = *(first+i);
  }
  for(int i = 0; i < n; i++){
    *(position + (last-first) + i) = ref[i];
  }
}

#endif
