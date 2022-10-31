#include<iostream>
#include<map>
#include<queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n >> m;
    map<int,int> toecard;
    for(int i = 0; i<n; i++){
        int pwr;
        cin >> pwr;
        toecard[pwr]++;
    }
    int check = 0;
    for(int i = 1; i <= m; i++){
        int num;
        cin >> num;
        queue<int> card;
        for(int j = 0; j < num ; j++){
            int cardpwr;
            cin >> cardpwr;
            card.push(cardpwr);
        }
        while(!card.empty()){
            map<int,int>::iterator it = toecard.upper_bound(card.front());
            map<int,int>::iterator itend = toecard.end();
            if(it != itend){
                (it->second) -= 1;
                if(it -> second == 0){
                    toecard.erase(it->first);
                }
            }
            else if(it == itend){
                check = 1;
                break;
            }
            card.pop();
        }
        if(check == 1){
            cout << i;
            break;
        }
    }
    if (check == 0){
        cout << m+1;
    }
    return 0;
}


