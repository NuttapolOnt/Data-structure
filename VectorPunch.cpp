#include <iostream>
#include <vector>

using namespace std;

vector<string> punch(vector<string> &v, vector<string>::iterator it,int k) {
    int count = 0;
    vector<string>::iterator ref1 = v.end();
    for (int i =1; (i<=k)&&(it+i < ref1); i++){
        v.erase(it+1);
    }
    for (int i =1; (i<=k)&&((it-i) >= v.begin()); i++){
        v.erase(it-i);
        count += 1;
    }
    v.erase(it-count);

    return v;
}

int main() {
    int n,j,k;
    cin >> n >> j >> k;
    vector<string> v(n);
    for (int i = 0;i < n;i++) {
        cin >> v[i]; 
    }
    cout << "Result after punch" << endl;
    vector<string> result = punch(v, v.begin() + j, k);
    for (auto &x : result) {
        cout << x << endl;
    }
}