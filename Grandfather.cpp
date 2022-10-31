#include<iostream>
#include<map>
#include<set>

int check(std::map<std::string,std::set<std::string>> &son, std::string s1, std::string s2){
    if(s1 == s2){
        return 0;
    }
    std::set<std::string> grandpa;
    for(std::string s : son[s1]){
        for(std::string x : son[s]){
            grandpa.insert(x);
        }
    }
    for(std::string y : son[s2]){
        for(std::string z : son[y]){
            if(grandpa.find(z) != grandpa.end()){
                return 1;
            }
        }
    }

    return 0;
}
int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n; int m;
    std::cin >> n >> m;
    std::map<std::string,std::set<std::string>> son; 
    for(int i = 0; i<n; i++){
        std::string x,y;
        std::cin >> x >> y;
        son[y].insert(x);
    }
    for(int j = 0; j<m; j++){
        std::string s1,s2;
        std::cin >> s1 >> s2;
        if(check(son,s1,s2) == 1){
            std::cout << "YES" << std::endl;
        }
        else{
            std::cout << "NO" << std::endl;
        }
    }
    return 0;
}