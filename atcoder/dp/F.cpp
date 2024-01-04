#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

int dp[3001][3001];

int lcs(string& s, string& t, int i, int j) {
    if(dp[i][j] != -1) return dp[i][j];
    if(i == 0 || j == 0) return dp[i][j] = 0;
    if(s[i-1] == t[j-1]) return dp[i][j] = 1 + lcs(s, t, i-1, j-1);
    return dp[i][j] = max(lcs(s, t, i-1, j), lcs(s, t, i, j-1));
}

void solve() {
    string s, t, ans = "";
    cin >> s >> t;
    memset(dp, -1, sizeof(dp));
    int n = s.size(), m = t.size();
    lcs(s, t, n, m);
    int i = n, j = m;
    while(i > 0 && j > 0) {
        if(s[i-1] == t[j-1]) {
            ans += s[i-1];
            i--; j--;
        }
        else {
            if(dp[i-1][j] > dp[i][j-1]) i--;
            else j--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
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