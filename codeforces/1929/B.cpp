#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long
#define ull unsigned long long

const int MOD = 998244353;


void solve() {
    int a, n; cin >> a >> n;
    if(n <= 4*(a - 1)) {
        n += (n%2);
        int ans = n/2;
        cout << ans << endl;
    }
    else {
        int ans = 2*(a-1); n -= (4*(a-1));
        ans += n;
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
