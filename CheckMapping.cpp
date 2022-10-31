#include<iostream>
#include<set>

int main(){
    int n;
    std::cin >> n;
    std::set<int> a;
    int check = 0;
    for(int i = 0; i < n; i++){
        int x;
        std:: cin >> x;
        a.insert(x);
        if (a.size() == i){
            check = 1;
            break;
        }
    }
    if (check == 1){
        std::cout << "NO" << std::endl;
    }
    else {
        if((*a.begin() == 1)&&(*(--a.end()) == n)){
            std::cout << "YES" << std::endl;
        }
        else{
            std::cout << "NO" << std::endl;
        }
    }
}