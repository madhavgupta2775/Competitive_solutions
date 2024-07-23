#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

void solve() {
    int n, k; cin >> n >> k;
    int ans = 0;
    if (k == 0) {
        cout << 0 << endl;
        return;
    }
    if (k <= n) {
        cout << 1 << endl;
        return;
    }
    else k -= n;
    ans = 1;
    for (int i = 1; i < n; i++) {
        if (k > (n - i)) {
            k -= (n - i);
            ans++;
        }
        if (k > 0) {
            k = max(0LL, k - (n - i));
            ans++;
        }
        else break;
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
