#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::list<T>::remove_all(const T& value) {
  //write your code here
  int s = mSize;
  iterator it = begin();
  for(int i = 0; i < s; i++){
    iterator itref = it.ptr -> next;
    if(it.ptr -> data == value){
      it.ptr -> prev -> next = it.ptr -> next;
      it.ptr -> next -> prev = it.ptr -> prev;
      delete it.ptr;
      it = itref;
      mSize -= 1;
    }
    else{
      it = itref;
    }
  }
}

#endif
