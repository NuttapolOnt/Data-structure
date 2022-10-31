#include<iostream>
#include<set>
#include<map>
#include<iomanip>
#include<cmath>

int main(){
    int n;
    std::cin >> n;
    std::map<int,std::pair<float,float>> sub;
    std::map<std::string,std::pair<float,float>> teach;
    for(int i = 0; i < n; i++){
        int s; std::string t; float r;
        std::cin >> s >> t >> r;
        sub[s].first += r; sub[s].second += 1.0;
        teach[t].first += r; teach[t].second += 1.0;
    }
    for(auto &x : sub){
        std::cout << std::fixed << std::setprecision(2) << x.first << " " << x.second.first/x.second.second << std::endl;
    }
    for(auto &y : teach){
        std::cout << std::fixed << std::setprecision(2) << y.first << " " << y.second.first/y.second.second << std::endl;
    }
    return 0;
}
