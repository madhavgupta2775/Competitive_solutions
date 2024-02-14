#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long
#define ull unsigned long long

const int MOD = 998244353;

int compute_dp(int i, int j, vector<int> &c, vector<string> &s, vector<vector<int>> &dp) {
    if(i == s.size()) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int ans = 1e18;
    string prev = s[i-1], curr = s[i], rev_curr = s[i]; reverse(rev_curr.begin(), rev_curr.end());
    if(prev <= curr) {
        ans = min(ans, compute_dp(i+1, 0, c, s, dp));
    }
    if(prev <= rev_curr) {
        reverse(s[i].begin(), s[i].end());
        ans = min(ans, c[i] + compute_dp(i+1, 1, c, s, dp));
        reverse(s[i].begin(), s[i].end());
    }
    return dp[i][j] = ans;
}

void solve() {
    int n; cin >> n;
    vector<int> c(n); forn(i, 0, n) cin >> c[i];
    vector<string> s(n); forn(i, 0, n) cin >> s[i];
    vector<vector<int>> dp(n, vector<int> (2, -1));
    int ans = compute_dp(1, 0, c, s, dp);
    reverse(s[0].begin(), s[0].end());
    ans = min(ans, c[0] + compute_dp(1, 1, c, s, dp));
    cout << (ans == 1e18 ? -1 : ans) << endl;
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
