#include <iostream>
#include <vector>

using namespace std;

void reverse(vector<int> &v,vector<int>::iterator a,vector<int>::iterator b) {
    int count = (b-a)/2;
    for(int i = 0; i<count; i++){
        int x = *(a+i);
        int y = *(b-(i+1));
        *(a+i) = y;
        *(b-(i+1)) = x;
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
    reverse(v,v.begin()+a,v.begin()+b+1);
  //display content of the vector
    for (auto &x : v) {
        cout << x << " ";
    }
    cout << endl;
}