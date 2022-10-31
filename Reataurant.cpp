#include<iostream>
#include<queue>
#include<vector>

int check (std::vector<int> &time, int i){
    int count = 0;
    for(int x : time){
        if((x!=0)&&(i%x == 0)){
            count += 1;
        }
        else if (x == 0){
            count +=1;
        }
    }
    return count;
}

int main(){
    int m,n;
    std::cin >> n >> m;
    std::vector<int> time(n);
    for(int i = 0; i<n ; i++){
        std::cin >> time[i];
    }
    int t = 0;
    while(m != 0){
        int q = check(time,t);
        for(int i = 0; i < q; i++){
            std::cout << t << '\n';
            m -= 1;
            if(m == 0){
                break;
            }
        }
        t+=1;
    }
    return 0;
}