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
int beeg(int n, int k, vector<int> &a, vector<int> &b, vector<int> &c, vector<vector<int>> &check){
    if(n == -1){
        return 0;
    }
    if(check[k][n] != -1){
        return check[k][n];
    }
    if(n == 0){
        if(k == 0)check[k][0] = max(a[0], b[0]);
        else if(k == 1)check[k][0] = max(a[0], c[0]);
        else{
            check[k][0] = max(b[0], c[0]);
        }
        return check[k][0];
    }
    if(k == 0){
        check[0][n] = max(a[n] + beeg(n-1, 2, a, b, c, check), b[n] + beeg(n-1, 1, a, b, c, check));
        return check[0][n];
    }
    else if(k == 1){
        check[1][n] = max(a[n] + beeg(n-1, 2, a, b, c, check), c[n] + beeg(n-1, 0, a, b, c, check));
        return check[1][n];
    }
    else{
        check[2][n] = max(c[n] + beeg(n-1, 0, a, b, c, check), b[n] + beeg(n-1, 1, a, b, c, check));
        return check[2][n];
    }
}

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n), c(n);
    vector<vector<int>> check(3, vector<int> (n, -1));
    forn(i, 0, n){
        cin >> a[i] >> b[i] >> c[i];
    }
    cout << max(a[n-1] + beeg(n-2, 2, a, b, c, check), max(b[n-1] + beeg(n-2, 1, a, b, c, check), c[n-1] + beeg(n-2, 0, a, b, c, check)));
}   
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    // cout << setprecision(30);
    // int T = 1;
    // cin >> T;
    // for(int I = 1; I <= T; I++) {
    //     solve(); 
    // }
    solve();
    return 0;
}