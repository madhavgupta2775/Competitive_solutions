#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long
#define ull unsigned long long

const int MOD = 998244353;

void solve() {
    int a, b, c; cin >> a >> b >> c;
    int ans = a;
    if((b % 3) && (c < (3 - b%3))) {
        cout << -1 << endl;
    }
    else {
        ans += b/3;
        c += b%3;
        ans += c/3;
        if(c%3) ans++;
        cout << ans << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(30);
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        solve();
    }
    return 0;
}