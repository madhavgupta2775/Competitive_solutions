#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (int &i : a) cin >> i;
    int ans = 0, prev = 0;
    for (int i = 0; i < n; i++) {
        if (prev && (prev - 1) * 2 < a[i] && a[i] <= 4 && a[i]) {
            if (prev == 2) prev = 1;
            else if (a[i] > 2) prev = 2;
            else {
                prev = 0;
                continue;
            }
        }
        else if (a[i] <= 2 && a[i]) {
            prev = 1;
        }
        else prev = 0;
        if (a[i]) ans++;
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
