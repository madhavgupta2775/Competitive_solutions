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
    int n, c0 = 0, c1 = 0; cin >> n;
    vector<int> v(n);
    forn(i, 0, n){
        cin >> v[i];
        if(v[i] == 0){
            c0++;
        }
        else if(v[i] == 1){
            c1++;
        }
    }
    if(c0 > n-c0+1){
        if(c0 + c1 != n || c1 == 0){
            cout << 1 << endl;
        }
        else{
            cout << 2 << endl;
        }
    }
    else{
        cout << 0 << endl;
    }
}   
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        solve(); 
    }
    // solve();
    return 0;
}