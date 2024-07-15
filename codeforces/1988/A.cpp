#include <bits/stdc++.h>
using namespace std;

#define endl "\n" 
#define int long long

const int MOD = 998244353;

void solve() {
    int n, k; cin >> n >> k;
    if(n == 1) {
        cout << 0 << endl;
        return;
    }
    if(n <= k) {
        cout << 1 << endl;
        return;
    }
    cout << 1 + (n - k) / (k - 1) + ((n - k) % (k - 1) != 0) << endl;
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