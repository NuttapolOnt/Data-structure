#include<iostream>
#include<map>

int main() {
    int n;
    std::cin >> n;
    std::map<std::string,int> count;
    for(int i = 0; i<n; i++){
        std::string x;
        std::cin >> x;
        count[x]++;
    }
    std::string key;
    int val;
    for(auto &x : count){
        if (x.second >= val) {
            key = x.first;
            val = x.second;
        }
    }
    std::cout << key << " " << val << std::endl;
    return 0;
}