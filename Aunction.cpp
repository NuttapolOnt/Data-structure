#include<iostream>
#include<queue>
#include<map>
#include<vector>

using namespace std;

int main() {
    map<pair<int,int>,int> member; // <name of member,product>,price
    map<int,int> product; // <name of product,quantity>
    map<int,priority_queue<pair<int,int>>> betprice;
    int M,N,A;
    cin >> N >> M >> A;
    for(int i = 1; i<=N; i++){
        int n;
        cin >> n;
        product[i] = n;
    }
    for(int i = 0; i<A; i++) {
        char option;
        cin >> option;
        if(option == 'B'){
            int U,I,V;
            cin >> U >> I >> V;
            pair<int,int> bet;
            bet.first = U;
            bet.second = I;
            member[bet] = V;
        }
        else if( option == 'W'){
            int U,I;
            cin >> U >> I;
            pair<int,int> withdraw;
            withdraw.first = U;
            withdraw.second = I;
            member[withdraw] = 0;
        }
    }
    for(auto &x : member){
        pair<int,int> price;
        price.first = x.second;
        price.second = x.first.first;
        betprice[x.first.second].push(price);
    }
    map<int,vector<int>> betwon;
    for(auto &x : betprice){
        int count = 0;
        while((!x.second.empty()) && (count < product[x.first]) && (x.second.top().first!=0)){
            betwon[x.second.top().second].push_back(x.first);
            x.second.pop();
            count++;
        }
    }
    for(int i = 1; i <= M; i++){
        if(betwon[i].size() == 0){
            cout << "NONE" << endl;
        }
        else{
            for(int y : betwon[i]){
                cout << y << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
