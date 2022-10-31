#include<iostream>
#include<set>

int main() {
    int n; int m;
    std::cin >> m >> n;
    std::set<int> a;
    std::set<int> ans;
    for(int i = 0; i<m; i++){
        int x;
        std::cin >> x;
        a.insert(x);
    }
    for(int j = 0; j<n; j++){
        int y;
        std::cin >> y;
        if(a.find(y)!= a.end() ){
            ans.insert(y);
        }
    }
    for(int z : ans){
        std::cout << z << " ";
    }
    return 0;
}
