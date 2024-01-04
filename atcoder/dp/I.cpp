#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

double dp[3000][3000];

double compute(int coins, int heads, vector<double> &a) {
    if(coins == 0) {
        if(heads == 0) return 1;
        else return 0;
    }
    if(heads < 0 || heads > coins) return 0;
    if(dp[coins][heads] < 0.5) return dp[coins][heads];
    dp[coins][heads] = a[coins-1]*compute(coins-1, heads-1, a) + (1-a[coins-1])*compute(coins-1, heads, a);
    return dp[coins][heads];
}

void solve() {
    int n; cin >> n;
    vector<double> a(n);
    forn(i,0,n) cin >> a[i];
    memset(dp, -1, sizeof(dp));
    double ans = 0;
    forn(i, (n+1)/2, n+1) {
        ans += compute(n, i, a);
    }
    cout << ans << endl;
}

 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << setprecision(30);
    int T = 1;
    // cin >> T;
    for(int I = 1; I <= T; I++) {
        solve();
    }
    return 0;
}