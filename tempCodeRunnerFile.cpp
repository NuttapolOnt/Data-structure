#include<iostream>
#include<math.h>

int main(){
    int n,k;
    std::cin >> n >> k;
    int ans = 0;
    if(k == 1){
        ans = n-1;
    }
    else if(n == 1){
        ans = 1;
    }
    else{
        ans = (log(n*(k-1))/log(k));
        if((pow(k, ans+1)-1)/(k-1) < n){
            ans += 1;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}