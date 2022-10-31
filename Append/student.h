#include "stack.h"
#include "queue.h"

namespace CP {
    template<typename T>
    void stack<T>::appendStack(stack<T> s) {
        int m = mSize;
        int n = s.size();
        T *ans = new T[m+n]();
        for(int i = 0; i < n; i++){
            ans[i] = s.mData[i];
        }
        for(int i = 0; i < m; i++){
            ans[n+i] = mData[i];
        }
        delete [] mData;
        mData = ans;
        mSize = m+n;
        mCap = m+n;
    }

    template<typename T>
    void stack<T>::appendQueue(queue<T> q) {
        int n = mSize;
        int m = q.size();
        T *ans = new T[m+n]();
        CP::stack<T> s;
        while(!q.empty()){
            s.push(q.front());
            q.pop();
        }
        for(int i = 0; (!s.empty()) && (i < m); i++){
            ans[i] = s.top();
            s.pop();
        }
        for(int i = 0; i < n; i++){
            ans[m+i] = mData[i];
        }
        delete [] mData;
        mData = ans;
        mSize = m+n;
        mCap = m+n;
    }

    template<typename T>
    void queue<T>::appendStack(stack<T> s) {
        while(!s.empty()){
            push(s.top());
            s.pop();
        }
    }

    template<typename T>
    void queue<T>::appendQueue(queue<T> q) {
        while(!q.empty()){
            push(q.front());
            q.pop();
        }
    }
}
