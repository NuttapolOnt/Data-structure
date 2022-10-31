#include<iostream>
#include<set>
#include<vector>
#include<algorithm>

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n,m,k;
    std::cin >> n >> m >> k;
    std::vector<int> all(n);;
    for(int i = 0; i < n; i++){
        int x;
        std::cin >> x;
        all[i] = x;
    }
    sort(all.begin(),all.end());
    for(int i = 0; i < m; i++){
        int ref;
        std::cin >> ref;
        int count = 0;
        std::vector<int>::iterator it1 = lower_bound(all.begin(), all.end(), ref-k);
        std::vector<int>::iterator it2 = upper_bound(it1,all.end(), ref+k);
        std::cout << it2-it1 << " ";
    }
    return 0;
}