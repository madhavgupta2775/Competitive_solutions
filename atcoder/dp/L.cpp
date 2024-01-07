#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

int dp[3000][3000];

int compute(int l, int r, vector<int> &a) { // [l, r]
    if(l > r) return 0;
    if(dp[l][r] != -1) return dp[l][r];
    return dp[l][r] = max(a[l] - compute(l+1, r, a), a[r] - compute(l, r-1, a));
}

void solve() {
    int n; cin >> n;
    memset(dp, -1, sizeof(dp));
    vector<int> a(n);
    forn(i,0,n) cin >> a[i];
    cout << compute(0, n-1, a) << endl;
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