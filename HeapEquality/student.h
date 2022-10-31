#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T,typename Comp >
bool CP::priority_queue<T,Comp>::operator==(const CP::priority_queue<T,Comp> &other) const {
  if(mSize == 0 && other.size() == 0){
    return true;
  }
  if(mSize != other.size()){
    return false;
  }
  CP::priority_queue<T,Comp> a(*this);
  CP::priority_queue<T,Comp> b(other);
  while(!a.empty()){
    if(a.top() != b.top()){
      return false;
    }
    a.pop();
    b.pop();
  }
  return true;
}

#endif
