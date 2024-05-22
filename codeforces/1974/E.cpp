#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

const int MOD = 1e9 + 7;

void solve() {
    int m, x; 
    cin >> m >> x;
    vector<pair<int, int>> a(m);
    int sum_h = 0;
    forn(i, 0, m) {
        cin >> a[i].first >> a[i].second;
        sum_h += a[i].second;
    }

    int MAX_H = sum_h + 1;
    vector<int> dp(MAX_H, 1e18);  // dp[h] will store the max cost remaining with exactly h happiness
    dp[0] = 0;  // Base case: 0 happiness requires 0 cost

    for (int i = 0; i < m; i++) {
        int cost = a[i].first;
        int happiness = a[i].second;
        for (int h = MAX_H - 1; h >= happiness; h--) {
            if (i * x >= cost + dp[h - happiness]) {
                dp[h] = min(dp[h], dp[h - happiness] + cost);
            }
        }
    }

    int ans = 0;
    for (int h = MAX_H - 1; h >= 0; h--) {
        if(dp[h] < 1e18) {
            ans = h;
            break;
        }
    }

    cout << ans << endl;
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
