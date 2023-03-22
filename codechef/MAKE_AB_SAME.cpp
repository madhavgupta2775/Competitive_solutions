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
    int n, count = 0; cin >> n;
    vector<int> a(n), b(n);
    forn(i, 0, n){
        cin >> a[i];
        if(a[i] == 1){
            count++;
        }
    }
    forn(i, 0, n){
        cin >> b[i];
    }
    forn(i, 0, n){
        if((a[0] == 0 && b[0] == 1) || (a[n-1] == 0 && b[n-1] == 1)){
            cout << "NO" << endl; return;
        }
        if((a[i] == 1 && b[i] == 0) || (count == 0 && a[i] == 0 && b[i] == 1)){
            cout << "NO" << endl; return;
        }
    }
    cout << "YES" << endl;
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