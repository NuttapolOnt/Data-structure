#include<iostream>

int main() {
    int a;
    std :: cin >> a;
    int count = 1;
    while(count < a){
        count *= 1;
    }
    std::cout << count - a << std::endl;
    return 0;
}