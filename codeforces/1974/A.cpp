#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

const int MOD = 1e9 + 7;

void solve() {
    int x, y; cin >> x >> y;
    int ans = y/2;
    x -= 7*ans;
    if(y%2) {
        ans++;
        x -= 11;
    }
    if(x < 0) {
        cout << ans << endl;
    }
    else {
        ans += (x/15);
        if(x%15) {
            ans++;
        }
        cout << ans << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << fixed << setprecision(30);
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        solve();
    }
    return 0;
}