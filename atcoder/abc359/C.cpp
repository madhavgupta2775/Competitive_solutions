#include <bits/stdc++.h>
using namespace std;

#define endl "\n" 
#define int long long

const int MOD = 1e9 + 7;

void solve() {
    int sx, sy; cin >> sx >> sy;
    int tx, ty; cin >> tx >> ty;
    int ans = abs(ty - sy);
    int off = ((sy - sx) % 2 + 2) % 2;
    if(off == 0 && sx < tx) off = 1;
    else if(off == 1 && sx < tx) off = 0;
    // cout << off << endl;
    ans += max((abs(sx - tx) - off - ans + 1) / 2, 0ll);
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
