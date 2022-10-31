#include <vector>
#include <algorithm>
#include <set>
using namespace std;

template <typename T>
vector<T> Union(const vector<T>& A, const vector<T>& B) {
    vector<T> v(A.size()+B.size());
    set<T> s;
    vector<bool> check(B.size());
    if (A.size() == 0){
        return B;
    }
    else if(B.size() == 0){
        return A;
    }
    
    else{
        for(int i = 0; i < A.size(); i++){
            s.insert(A[i]);
            v[i] = A[i];
        }
        int count = 0;
        for(int i = 0; i < B.size(); i++){
            auto it = s.find(B[i]);
            if(it == s.end()){
                v[count + A.size()] = B[i];
                count++;
            }
        }
        v.resize(count+A.size());
    }
    return v;
}

template <typename T>
vector<T> Intersect(const vector<T>& A, const vector<T>& B) {
    vector<T> v(A.size());
    if((A.size() == 0) || (B.size() == 0)){
        v = {};
    }
    else{
        set<T> s;
        int count = 0;
        for(T x : B){
            s.insert(x);
        }
        for(T x : A){
            auto it = s.find(x);
            if(it != s.end()){
                v[count] = x;
                count++;
                s.erase(it);
            }
        }
        v.resize(count);
    }
    return v;
}
