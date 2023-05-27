#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long
#define ff first
#define ss second

// const int MOD2 = 1e9+7;
// const int MOD = 998244353;

void solve() {
    int n, m, ans = 0; cin >> n >> m;
    vector<vector<int>> v(n, vector<int> (n));
    vector<int> temp(n);
    forn(i, 0, m){
        for(int j = 0; j < n; j++){
            cin >> temp[j];
            if(j > 0){
                v[temp[j]-1][temp[j-1]-1] = 1;
                v[temp[j-1]-1][temp[j]-1] = 1;
            }
        }
    }
    forn(i, 0, n){
        for(int j = 0; j < n; j++){
            if(v[i][j] == 0 && i != j){
                ans++;
            }
        }
    }
    cout << ans/2 << endl;
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