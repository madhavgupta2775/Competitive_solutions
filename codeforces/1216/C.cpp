#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

const int MOD = 998244353;

void solve() {
    // check if 2 black sheets completely cover the white sheet
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2; // white sheet
    int x3, y3, x4, y4; cin >> x3 >> y3 >> x4 >> y4; // black sheet 1
    int x5, y5, x6, y6; cin >> x5 >> y5 >> x6 >> y6; // black sheet 2
    // check if black sheet 1 covers white sheet
    if(x3 <= x1 && x4 >= x2 && y3 <= y1 && y4 >= y2) {
        cout << "NO" << endl;
    }
    else if(x5 <= x1 && x6 >= x2 && y5 <= y1 && y6 >= y2) {
        cout << "NO" << endl;
    }
    else {
        // check if both black sheets combined cover white sheet
        if(max(x3, x5) <= x1 && min(x4, x6) >= x2) {
            // check if they overlap in y
            if((y4 < y5) || (y6 < y3)) {
                cout << "YES" << endl;
                return;
            }
            if(min(y3, y5) <= y1 && max(y4, y6) >= y2) {
                cout << "NO" << endl;
                return;
            }
            else {
                cout << "YES" << endl;
                return;
            }
        }
        else if(max(y3, y5) <= y1 && min(y4, y6) >= y2) {
            // check if they overlap in x
            if((x4 < x5) || (x6 < x3)) {
                cout << "YES" << endl;
                return;
            }
            if(min(x3, x5) <= x1 && max(x4, x6) >= x2) {
                cout << "NO" << endl;
                return;
            }
            else {
                cout << "YES" << endl;
                return;
            }
        }
        else {
            cout << "YES" << endl;
            return;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(30);
    int T = 1;
    // cin >> T;
    for(int I = 1; I <= T; I++) {
        solve();
    }
    return 0;
}
