#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

void solve() {
    int n, w; cin >> n >> w;
    vector<int> pdp(n*1100, 1e18), ndp(n*1100, 1e18), val(n), wt(n);
    forn(i,0,n) cin >> wt[i] >> val[i];
    ndp[0] = 0; pdp[0] = 0;
    forn(i, 0, n) {
        for(int j = 0; j < ndp.size(); j++) {
            if(j >= val[i]) 
                ndp[j] = min(ndp[j], pdp[j- val[i]] + wt[i]);
        }
        pdp = ndp;
    }
    for(int j = ndp.size()-1; j >= 0; j--) {
        if(ndp[j] <= w) {
            cout << j << endl;
            return;
        }
    }
}
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    // cout << setprecision(30);
    int T = 1;
    // cin >> T;
    for(int I = 1; I <= T; I++) {
        solve();
    }
    return 0;
}