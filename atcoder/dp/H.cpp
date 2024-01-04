#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

int dp[1001][1001];
const int mod = 1e9+7;

int compute(int i, int j, int h, int w, vector<vector<char>>& arr) {
    if(i == h-1 && j == w-1) {
        return 1;
    }
    if(i >= h || j >= w || arr[i][j] == '#') {
        return 0;
    }
    if(dp[i][j] != -1) {
        return dp[i][j];
    }
    dp[i][j] = (compute(i+1, j, h, w, arr) + compute(i, j+1, h, w, arr))%mod;
    return dp[i][j];
}

void solve() {
    int h, w; cin >> h >> w;
    vector<vector<char>> arr(h, vector<char>(w));
    forn(i,0,h) {
        forn(j,0,w) {
            cin >> arr[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << compute(0, 0, h, w, arr) << endl;
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