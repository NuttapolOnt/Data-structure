void replace(const T& x, list<T>& y) {
  //write your code here
  iterator it = begin();
  iterator itend = end();
  while(it != itend){
    iterator itref = it.ptr -> next;
    if(it.ptr -> data == x){
      iterator ybeg = y.begin();
      iterator yend = y.end();
      while(ybeg != yend){
        insert(it, ybeg.ptr -> data);
        ++ybeg;
      }
      erase(it);
    }
    it = itref;  
  }
}