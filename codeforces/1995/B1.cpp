#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

void solve() {
    int n, m; cin >> n >> m;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        mp[x]++;
    }
    int ans = 0;
    for (auto x: mp) {
        if (x.second == 0) continue;    
        int a = min(x.second, m / x.first);
        int b = min((m - a * x.first) / (x.first + 1), mp[x.first + 1]);
        int c = min(min(m - a * x.first - b * (x.first + 1), mp[x.first + 1] - b), a);
        ans = max(ans, (a - c) * x.first + (b + c) * (x.first + 1));
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
