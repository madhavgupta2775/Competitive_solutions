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
    int n, sum = 0,temp1 = 0, temp2=0, a = 1, b = 1; cin >> n;
    vector<pair<int, int>> v(n);
    forn(i, 0, n){
        cin >> v[i].first; cin >> v[i].second;
    }
    forn(i, 1, n){
        temp1= a; temp2 = b;
        if(v[i].first == v[i-1].first){
            a -= temp1;
        }
        if(v[i].first != v[i-1].second){
            a += temp2;
        }
        if(v[i].second != v[i-1].first){
            b += temp1;
        }
        if(v[i].second == v[i-1].second){
            b -= temp2;
        }
        a %= MOD; b %= MOD;
    }
    cout << (a+b)%MOD << endl;
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