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
    int l, r, n = 1, x = 0, temp = 0, m = 1, count = 1; cin >> l >> r;
    temp = l*2;
    while(r >= temp){
        n++; temp <<= 1;
    }
    x = 1 + ((r-l*binpow(2, n-1))/binpow(2, n-1));
    if(n > 1){
        temp = 1; count = l*3*binpow(2, n-2);
        while(r >= count && m < n){
            temp *= max(1ll, n-m); temp /= m;
            x += (1 + (r-count)/(count/l))*temp;
            m++; count *= 3; count /= 2;
        }
    }
    cout << n << " " << x << endl;
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