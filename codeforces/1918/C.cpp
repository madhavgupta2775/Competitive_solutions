#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

const int MOD = 1e9 + 7;

void solve() {
    int a, b, r; cin >> a >> b >> r;
    if(a < b) swap(a, b);
    int ans = LONG_LONG_MAX;
    int tempr = r, tempa = a, tempb = b;
    for(int j = 63; j >= 0; j--) {
        for(int i = j; i >= 0; i--) {
            if((1ll << i & a) && !(1ll << i & b)) {
                if(r >= (1ll << i)) {
                    a ^= (1ll << i);
                    b ^= (1ll << i);
                    r -= (1ll << i);
                }
            }
            if(a < b) swap(a, b);
        }
        ans = min(ans, abs(a - b));
        a = tempa, b = tempb, r = tempr;
    }
    cout << ans << endl;
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
    return 0;
}