#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::block_swap(iterator a, iterator b, size_t m) {
  //write your code here
  if((a == b) || (m == 0)){
    return false;
  }
  if(a < begin() || b < begin()){
    return false;
  }
  if(a >= end() || b >= end()){
    return false;
  }
  if(end() - a < m){
    return false;
  }
  if(end() - b < m){
    return false;
  }
  int checka = a-begin();
  int checkb = b-begin();
  if(checkb > checka){
    if(b - a < m){
      return false;
    }
  }
  if(checka > checkb){
    if(a-b < m){
      return false;
    }
  }
  for(int i = 0; i < m; i++){
    std::swap(*(a+i), *(b+i));
  }
  return true;
}

#endif
