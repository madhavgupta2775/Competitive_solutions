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
    int n, temp = 1; cin >> n;
    vector<vector<int>> v(n, vector<int> (n));
    forn(i, 0, n){
        for(int j = 0; j < n; j++){
            if(temp <= n*n){
                v[i][j] = temp;
            }
            else{
                temp = 2;
                v[i][j] = temp;
            }
            temp += 2;
        }
    }
    forn(i, 0, n){
        for(int j = 0; j < n; j++){
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
    // solve();
    return 0;
}