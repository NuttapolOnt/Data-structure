#include<iostream>
#include<map>
#include<set>

// void printset(std::set<std::pair<int,std::string>> &ans){
//     for(auto &x : ans){
//         std::cout << "<" << x.second << " " << x.first << ">" << std::endl;
//     }
// }

int main(){
    int n,k;
    std::cin >> n >> k;
    std::map<std::string,int> a;
    std::set<std::pair<int,std::string>> ans; 
    for(int i = 0; i < n; i++){
        std::string x;
        std::cin >> x;
        a[x]++;
    }
    for(auto &z : a){
        std::pair<int,std::string> y;
        y.first = z.second;
        y.second = z.first;
        ans.insert(y);
    }
    auto it = ans.begin();
    if(k>a.size()){
        k = a.size();
    }
    for(int j = 0 ; j<(a.size()-k) ; j++){
        it++;
    }
    std::cout << (*it).first << std::endl;
    return 0;
}