#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

int dp[100005];  

// int compute(int &n, int k, vector<int>& a) {
//     if(k == 0) return 0;
//     if(k < 0) return 1;
//     if(dp[k] != -1) return dp[k];
//     forn(i, 0, n) {
//         if(compute(n, k - a[i], a) == 0) { 
//             return dp[k] = 1;
//         }
//     }
//     return dp[k] = 0;
// }

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    forn(i,0,n) cin >> a[i];
    memset(dp, -1, sizeof(dp));
    forn(i, 0, k+1) {
        if(k == 0) dp[i] = 0;
        else {
            for(int j = 0; j < n; j++) {
                if(i - a[j] >= 0) {
                    if(dp[i - a[j]] == 0) dp[i] = 1;
                }
            }
            if(dp[i] == -1) dp[i] = 0;
        }
    }
    if(dp[k] == 1) cout << "First" << endl;
    else cout << "Second" << endl;
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