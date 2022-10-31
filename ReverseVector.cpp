#include <iostream>
#include <vector>
using namespace std;
void reverse(vector<int> &v,int a,int b) {
    int n;
    n = (b-a)+1;
    int s[n] ;
    for(int i = b; i >= a; i--){
        int x = v[i];
        s[b-i] = x; 
    }
    for (int j = a; j <= b; j++){
        v[j] = s[j-a];
    }
}
int main() {
  //read input
    int n,a,b;
    cin >> n;
    vector<int> v;
    for (int i = 0;i < n;i++) {
        int c;
        cin >> c;
        v.push_back(c);
    }
    cin >> a >> b;
  //call function
    reverse(v,a,b);
  //display content of the vector
    for(int i =0 ; i<n ; i++){
        if (i==(n-1)){
            cout << v[i];
        }
        else {
            cout << v[i] << " ";
        }
    }
    cout << endl;
    
    // for (auto &x : v){
    //     cout << x << " ";
    // }
    // cout << endl;
    // return 0;
}