#include <bits/stdc++.h>
using namespace std;

#define endl "\n" 
#define int long long

const int MOD = 998244353;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (int i = 0; i < n; i++) cin >> a[i];
    stack<pair<int, int>> s;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if(s.empty()) {
            s.push(make_pair(a[i], 1));
            ans += a[i];
            if(i == 0) ans++;
        }
        else {
            int w = 0, count = 0;
            while(!s.empty() && s.top().first < a[i]) {
                w += s.top().second; count += s.top().first * s.top().second;
                s.pop();
            }
            ans += (w + 1) * a[i] - count;
            s.push(make_pair(a[i], w + 1));
        }
        cout << ans << " ";
    }
    cout << endl;
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
