#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::insert_many(CP::vector<std::pair<int,T>> data) {
  //write your code here
  T *ans = new T[mSize + data.size()]();
  CP::vector<std::pair<bool,T>> check(mSize+1);
  for(int i =  0; i < (mSize + 1); i++){
    check[i].first = false; 
  }
  for(int i = 0; i < data.size(); i++){
    check[data[i].first].first = true;
    check[data[i].first].second = data[i].second;
  }
  int count = 0;
  for(int i = 0; i < mSize; i++){
    if(check[i].first == true){
      ans[i+count] = check[i].second;
      count += 1;
      ans[i+count] = *(mData+i);
    }
    else{
      ans[i+count] = *(mData+i);
    }
  }
  if((*(check.end()-1)).first){
    ans[mSize + data.size()-1] = (*(check.end()-1)).second;
  }
  mData = ans;
  mSize = mSize + data.size();
  mCap = mSize + data.size();
}

#endif
