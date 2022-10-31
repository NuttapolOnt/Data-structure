#include<iostream>
#include<map>
#include<vector>
#include<queue>

int main(){
    int n;
    std::cin >> n;
    std::priority_queue<std::string,std::vector<std::string>,std::greater<std::string>> pq;
    for(int i = 0; i<n; i++){
        std::string x;
        std::cin >> x;
        pq.push(x);
    }
    while(!pq.empty()){
        int count = 1;
        std::string ref = pq.top();
        pq.pop();
        while(!pq.empty() && (pq.top() == ref)){
            count++;
            pq.pop();
        }
        if(count > 1){
            std::cout << ref << " " << count << '\n';
        }
    }
    return 0;
}