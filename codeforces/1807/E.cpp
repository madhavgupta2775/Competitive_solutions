#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)
// #define endl "\n" 
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
    int n, l = 0, r = 0, temp = 0, extra = 0; cin >> n;
    vector<int> v(n), psum(n); r = n;
    forn(i, 0, n){
        cin >> v[i];
        if(i == 0){
            psum[i] = v[i];
        }
        else{
            psum[i] = psum[i-1] + v[i];
        }
    }
    while(r != l || v[l] != temp-1){
        extra = r; r = (r+l)/2;
        cout << "? " << r-l+1 << " ";
        forn(i, l, r+1){
            cout << i+1 << " ";
        }
        cout << endl; cout.flush();
        cin >> temp;
        if(temp == psum[r] - psum[l] + v[l]){
            l = r+1; r = extra;
        }
    }
    cout << "! " << l+1 << endl; cout.flush();
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