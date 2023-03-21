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
    // int n, m, i1, j1, i2, j2; cin >> n >> m >> i1 >> j1 >> i2 >> j2;
    // string s; cin >> s;
    // vector<vector<int>> v(n, vector<int> (m));
    int n, ones = 0, sum = 0; cin >> n;
    vector<int> v, c(n);
    forn(i, 0, n){
        cin >> c[i];
        if(c[i] == 1){
            ones++;
        }
    }
    v.push_back(1);
    if(c == v){
        cout << "YES" << endl;
    }
    else if(ones >= 2){
        sort(c.begin(), c.end());
        sum += 1;
        forn(i, 1, n){
            if(c[i] > sum){
                cout << "NO" << endl; return;
            }
            sum += c[i];
        }
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
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