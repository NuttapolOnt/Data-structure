#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void printvec(vector<int> &v){
    for (int i = 0; i<(v.size()-1); i++){
        cout << v[i] << " ";
    }
    cout << v[v.size()-1] << endl;
}

int check(string &a){
    if (a.compare("pb")==0) return 1;
    else if (a.compare("sa")==0) return 2;
    else if (a.compare("sd")==0) return 3;
    else if (a.compare("r") ==0) return 4;
    else if (a.compare("d")==0) return 5;
    return 0;
}

int main (){
    vector<int> v ;
    int Q;
    cin >> Q;
    string option ;
    for (int i = 0; i<Q; i++){
        cin >> option;
        switch (check(option)){
            case 1 : 
                int x ;
                cin >> x;
                v.push_back(x);
                break;
            case 2 :
                sort(v.begin(),v.end());
                break;
            case 3 :
                sort(v.begin(),v.end(),greater<int>());
                break;
            case 4 :
                for (int i = 0; i < (v.size()/2); i++){
                    if (v.begin() == (v.end()-(i+1))) break;
                    int x ;
                    int y ;
                    x = v[i];
                    y = v[v.size()-(1+i)];
                    v[i] = y;
                    v[v.size()-(i+1)] = x;
                }
                break;
            case 5 :
                int z ;
                cin >> z;
                v.erase(v.begin()+z);
                break;
        }
    }
    printvec(v);
    return 0;
}