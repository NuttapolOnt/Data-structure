#include<iostream>
#include<set>
#include<map>

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n; int m;
    std::cin >> n >> m;
    std::set<std::pair<int,int>> all;
    for(int i = 0; i<n; i++){
        std::pair<int,int> x;
        std::cin >> x.first >> x.second;
        all.insert(x);
    }
    for(int i = 0; i<m; i++){
        int y,m;
        std::cin >> y >> m;
        std::pair<int,int> ref;
        ref.first = y;
        ref.second = m;
        if((all.find(ref) == all.end()) && (all.lower_bound(ref) == all.begin())){
            std::cout << -1 << " " << -1 << " ";
        }
        else if (all.find(ref) != all.end()){
            std::cout << 0 << " " << 0 << " ";
        }
        else{
            std::cout << (*(--all.lower_bound(ref))).first << " " << (*(--all.lower_bound(ref))).second << " ";
        }
    }
    return 0;
}