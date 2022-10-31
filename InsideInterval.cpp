#include<iostream>
#include<map>

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n,m;
    std::cin >> n >> m;
    std::map<int,std::pair<int,int>> all;
    for(int i = 0; i < n; i++){
        int start,stop;
        std::cin >> start >> stop;
        std::pair<int,int> x;
        x.first = start;
        x.second = stop;
        all[start] = x;
    }
    for(int i = 0; i<m ; i++){
        int ref;
        std::cin >> ref;
        if(ref < all.begin() -> first){
            std::cout << 0 << " ";
        }
        else if(ref > ((--all.end()) -> second).second){
            std::cout << 0 << " ";
        }
        else{
            auto it = all.lower_bound(ref);
            if (it -> first == ref){
                std::cout << 1 << " " ;
            }
            else if (ref <= (((--it)->second).second)){
                std::cout << 1 << " ";
            }
            else {
                std::cout << 0 << " " ;
            }
        }
    }
    return 0;
}