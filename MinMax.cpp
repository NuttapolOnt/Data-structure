#include <iostream>

using namespace std;
string check(int r, int c, int r1, int r2, int c1, int c2) {
    if (r1>r2) {
        return "INVALID";
    }
    else if (c1>c2) {
        return "INVALID";
    }
    else if ((c1>c) || (r1>r)) {
        return "OUTSIDE" ;
    }
    return "0";
}
bool possible(int r, int c, int r1, int r2, int c1, int c2) {
    if (r1>r2) {
        return false;
    }
    else if (c1>c2) {
        return false;
    }
    else if ((c1>c) || (r1>r)) {
        return false ;
    }
    return true;
}
int main() {
    int m; int n ;
    cin >> n ; cin >> m ;
    int num;
    cin >> num ;
    int mat[n][m];
    for (int i = 0; i<n ; i++){
        for (int j = 0 ; j<m ; j++) {
            int x;
            cin >> x;
            mat[i][j] = x;
        }
    }
    for (int k = 0; k<num; k++) {
        int Max ;
        int r1; int c1; int r2; int c2;
        cin >> r1 ;
        cin >> c1 ;
        cin >> r2 ;
        cin >> c2 ;
        if (!possible(n,m,r1,r2,c1,c2)) {
            cout << check(n,m,r1,r2,c1,c2) << endl;
        }
        else {
            Max = mat[r1-1][c1-1];
            for( int i = (r1-1) ; (i<n) && (i<r2) ; i++){
                for (int j = (c1-1); (j<m) && (j<c2) ; j++){
                   if (mat[i][j]>Max){
                       Max = mat[i][j];
                   }
                }    
            }
            cout << Max << endl ;
        }
    }    
    return 0;
}