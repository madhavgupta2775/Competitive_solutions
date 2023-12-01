#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

void solve() {
    int n, w; cin >> n >> w;
    vector<int> val(n), wt(n);
    forn(i,0,n) cin >> wt[i] >> val[i];
    vector<vector<int>> dp(n+1, vector<int>(w+1, 0));
    forn(i,1,n+1) {
        forn(j,1,w+1) {
            if(wt[i-1] <= j) {
                dp[i][j] = max(dp[i-1][j], val[i-1] + dp[i-1][j-wt[i-1]]);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[n][w] << endl;
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