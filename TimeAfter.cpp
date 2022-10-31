#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main () {
    int a ;
    int b ;
    int c ;
    cin >> a ;
    cin >> b ;
    cin >> c ;
    int p ;
    int q ;
    p = (b+c) / 60;
    q = (b+c) % 60 ;
    int ans1 ;
    int ans2 ;
    ans1 = a+p;
    ans2 = q ;
    if (ans1 >= 24) {
        ans1 %= 24;
    }
    if ( (ans1 < 10) && (ans2 < 10)) {
        cout << "0" << ans1 << " " << "0" << ans2 << endl ;
        return 0;
    }
    else if (ans1 < 10) {
        cout << "0" << ans1 << " " << ans2 << endl ;
        return 0;
    }
    else if (ans2 < 10) {
        cout << ans1 << " " << 0 << ans2 << endl;
        return 0;
    }
    else {
        cout << ans1 << " " << ans2 << endl ;
        return 0;
    }
}
