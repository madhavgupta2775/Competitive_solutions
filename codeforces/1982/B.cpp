#include <bits/stdc++.h>
using namespace std;

#define endl "\n" 
#define int long long

const int MOD = 998244353;

void solve() {
    int x, y, k; cin >> x >> y >> k;
    int t = y - (x % y);
    while(t < k) {
        int old_x = x;
        k -= t; x += t; 
        while(x % y == 0) {
            x /= y;
        }
        t = y - (x % y);
        if(old_x == x) {
            k %= t;
            break;
        }
        if(t == y) break;
    }
    int ans = x + k;
    while (ans % y == 0) {
        ans /= y;
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
