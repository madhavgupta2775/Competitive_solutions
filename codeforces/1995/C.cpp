#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    vector<int> ans(n);
    for (int i = 1; i < n; i++) {
        int cur = a[i], prev = a[i - 1];
        if (prev == 1) {
            continue;
        }
        else if (cur == 1) {
            cout << -1 << endl;
            return;
        }
        if (prev < cur) {
            int temp = 0;
            while (prev <= cur) {
                prev *= prev;
                temp++;
            }
            ans[i] = max(0ll, ans[i - 1] - temp + 1);
        }
        else {
            int temp = 0;
            while (prev > cur) {
                cur *= cur;
                temp++;
            }
            ans[i] = ans[i - 1] + temp;
        }
    }
    cout << accumulate(ans.begin(), ans.end(), 0ll) << endl;
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
