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
    int a, b, c, d, og = 0, temp = 0, offset = 0; cin >> a >> b >> c >> d;
    if(b == 1 || d == 1){
        cout << max(b, d) << endl;
    }
    else if((a+1)%b == 0 || (c+1)%d == 0){
        if((a+1)%b == 0 && (c+1)%d == 0){
            cout << 1 << endl;
        }
        else{
            a %= b; c %= d;
            cout << lcm(b, d) - a << endl;
        }
    }
    else{
        cout << 1 << endl;
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