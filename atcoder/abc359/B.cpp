#include <bits/stdc++.h>
using namespace std;

#define endl "\n" 
#define int long long

const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<int> a(2 * n); for (int i = 0; i < 2 * n; i++) cin >> a[i];
    int ans = 0;
    for (int i = 0; i < 2 * n - 2; i++) {
        if(a[i] == a[i + 2]) ans++;
    }
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
