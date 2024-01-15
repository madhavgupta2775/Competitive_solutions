#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

const int mod = 1e9+7;

void solve() {
    int h, w, xa, xb, ya, yb; cin >> h >> w >> ya >> xa >> yb >> xb;
    int dist = yb - ya - 1;
    int d = -1, e = -1;
    if(ya >= yb) {
        cout << "DRAW" << endl;
        return;
    }
    if(xa < xb) {
        if(max(1ll, xa- (dist+1)/2) +1 < max(1ll, xb - (dist)/2)) {
            d = 0;
        }
        if(min(w, xa + (dist+1)/2) + 1 < min(w, xb + (dist)/2)) {
            e = 0;
        }
    }
    else if(xa > xb) {
        if(min(w, xa + (dist+1)/2) > 1 + min(w, xb + (dist)/2)) {
            d = 0;
        }
        if(max(1ll, xa- (dist+1)/2) >  1 +  max(1ll, xb - (dist)/2)) {
            e = 0;
        }
    }
    if(dist % 2 == 0) {
        if(e == 0) {
            cout << "DRAW" << endl;
        }
        else {
            cout << "ALICE" << endl;
        }
    }
    else {
        if(d == 0) {
            cout << "DRAW" << endl;
        }
        else {
            cout << "BOB" << endl;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << setprecision(30);
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        solve();
    }
    return 0;
}