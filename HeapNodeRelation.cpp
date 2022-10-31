#include<iostream>
#include<math.h>
int main(){
    int n,m;
    std::cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a,b;
        std::cin >> a >> b;
        int checka = 0;
        int checkb = 0;
        if(a == b){
            std::cout << "a and b are the same node" << std::endl;
            checka = 2;
            checkb = 2;
        }
        
        if(a > b){
            while(a > 0){
                a = (a-1)/2;
                if(a == b){
                    checkb = 1;
                    break;
                }
            }
        }
        else if (b >= a){
            while(b > 0){
                b = (b-1)/2;
                if(a == b){
                    checka = 1;
                    break;
                }
            }
        }
        if(checka == 1){
            std::cout << "a is an ancestor of b" << std::endl;
        }
        else if(checkb == 1){
            std::cout << "b is an ancestor of a" << std::endl;
        }
        else if(checka == 0 && checkb == 0){
            std::cout << "a and b are not related" << std::endl;
        }
    }
    return 0;
}

