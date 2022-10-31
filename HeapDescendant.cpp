#include<iostream>
#include<math.h>
#include<vector>

int main(){
    int n,a;
    std::cin >> n >> a;
    int d = log2(a+1);
    int dep = log2(n+1);
    int beg = a;
    int end = a;
    if(d == dep){
        std::cout << 0 << std::endl;
        std::cout << a << std::endl;
    }
    else{
        std::vector<int> ans;
        ans.push_back(a);
        while(d < dep){
            d++;
            beg = (beg*2) +1;
            end = (end*2) +2;
            if(end >= n){
                end = n-1;
            }
            for(int i = beg; i <= end; i++){
                ans.push_back(i);
            }
        }
        std::cout << ans.size() << std::endl;
        for(int i = 0; i < ans.size(); i++){
            std::cout << ans[i] << " ";
        }
    }
    return 0;
}