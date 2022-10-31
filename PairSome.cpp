#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

int check(int n, std::set<int> &s1, std::set<int> &s2, std::vector<int> &v, int ref){
    for(int i = 0; i<n; i++){
        int x;
        x = v[i];
        if (ref >= x) {
            std::set<int>::iterator it = s1.find(ref-x);
            if((it != s1.end()) && (ref-x != x)){
                return 1;
            }
            else if ((it != s1.end()) && (ref-x == x) && (s2.find(ref-x) != s2.end()) ){
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int n; int m;
    std::cin >> n >> m;
    std::vector<int> v(n);
    std::set<int> s1;
    std::set<int> s2;
    for (int i =0; i<n; i++){
        int x;
        std::cin >> x;
        v[i] = x;
        if (s1.find(x) != s1.end()) {
            s2.insert(x);
        }
        s1.insert(x);
    }
    for(int j = 0; j<m; j++){
        int ref;
        std::cin >> ref;
        if (check(n,s1,s2,v,ref) == 1){
            std::cout << "YES" << std::endl;
        }
        else {
            std::cout << "NO" << std::endl;
        }
    }
    return 0;
}




