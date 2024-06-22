#include <bits/stdc++.h>
using namespace std;

#define endl "\n" 
#define int long long

const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<vector<bool>> a(n, vector<bool> (n));
    int temp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> temp;
            a[i][j] = temp;
        }
    }
    int count = (1 << n);
    vector<int> dp(count); dp[0] = 1;
    for (int i = 0; i < count; i++) {
        int ones = __builtin_popcount(i);
        for (int j = 0; j < n; j++) {
            if((1 << j) & i || !a[ones][j]) continue;
            (dp[i | (1 << j)] += dp[i]) %= MOD;
        }
    }
    cout << dp[(1 << n) - 1] << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
