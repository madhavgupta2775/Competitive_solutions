#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<int> a(n); forn(i, 0, n) cin >> a[i];
    // find lcm of all elements
    int lcm = a[0];
    forn(i, 1, n) {
        lcm = lcm * a[i] / __gcd(lcm, a[i]);
    }
    // cout << lcm << endl;
    int possible = 1;
    int coins = lcm - 1;
    vector<int> ans(n);
    forn(i, 0, n) {
        coins -= lcm / a[i];
        ans[i] = lcm / a[i];
        if(coins < 0) {
            possible = 0;
            break;
        }
    }
    if(!possible) {
        cout << -1 << endl;
    }
    else {
        for(auto x: ans) cout << x << " ";
        cout << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
