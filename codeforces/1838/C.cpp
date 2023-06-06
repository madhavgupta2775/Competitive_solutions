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
    int n, m, curr = 1; cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    forn(i, 0, n){
        if(i%2){
            for(int j = 0; j < m; j++){
                v[i][j] = curr;
                curr++;
            }
        }
    }
    forn(i, 0, n){
        if(i%2 == 0){
            for(int j = 0; j < m; j++){
                v[i][j] = curr;
                curr++;
            }
        }
    }
    forn(i, 0, n){
        forn(j, 0, m){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}   
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    // cout << setprecision(30);
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        solve(); 
    }
    return 0;
}