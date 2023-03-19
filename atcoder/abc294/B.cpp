#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long
#define ff first
#define ss second

const int MOD2 = 1e9+7;
const int MOD = 998244353;

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void solve() {
    int h, w; cin >> h >> w;
    vector<vector<int>> v(h, vector<int> (w));
    vector<vector<char>> ans(h, vector<char> (w));
    forn(i, 0, h){
        for(int j = 0; j < w; j++){
            cin >> v[i][j];
            if(v[i][j] == 0){
                ans[i][j] = '.';
            }
            else{
                ans[i][j] = 'A' + v[i][j] - 1;
            }
        }
    }
    forn(i, 0, h){
        for(int j = 0; j < w; j++){
            cout << ans[i][j];
        }
        cout << endl;
    }
}   
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    // int T = 1;
    // cin >> T;
    // for(int I = 1; I <= T; I++) {
    //     solve(); 
    // }
    solve();
    return 0;
}