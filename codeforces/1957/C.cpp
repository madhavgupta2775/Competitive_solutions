#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

const int MOD = 1e9 + 7;

int dp[300005];

int compute(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(dp[n] != -1) return dp[n];
    int ans = compute(n-1);
    ans = (ans + (2 * (n-1) * compute(n-2) % MOD) % MOD) % MOD;
    dp[n] = ans;
    return dp[n];
}

void solve() {
    int n, k; cin >> n >> k;
    int placed = 0;
    int r, c;
    map<pair<int, int>, int> mp;
    forn(i, 0, k) {
        cin >> r >> c;
        placed++;
        mp[{r, c}] = 1;
        if(mp[{c, r}] == 0) {
            placed++;
            mp[{c, r}] = 1;
        }
    }
    int count = n - placed;
    if(count == 0) {
        cout << 1 << endl;
        return;
    }
    cout << compute(count) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << fixed << setprecision(30);
    int T = 1;
    memset(dp, -1, sizeof(dp));
    dp[2] = 3;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        solve();
    }
    return 0;
}