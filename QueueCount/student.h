#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <map>

template <typename T>
std::vector<std::pair<T,size_t>> CP::queue<T>::count_multi(std::vector<T> &k) const {
    //write your code here
    std::vector<std::pair<T,size_t>> ans;
    std::map<T,int> check;
    for(int i = 0; i < mSize; i++){
        check[mData[(mFront + i) % mCap]]++;
    }
    for(T x : k){
        std::pair<T,size_t> a;
        a.first = x;
        a.second = check[x];
        ans.push_back(a);
    }
    return ans; 
}

#endif
