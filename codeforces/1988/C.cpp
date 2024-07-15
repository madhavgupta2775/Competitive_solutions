#include <bits/stdc++.h>
using namespace std;

#define endl "\n" 
#define int long long

const int MOD = 998244353;

void solve() {
    int n; cin >> n;
    bitset<64> b(n);
    if(b.count() == 1) {
        cout << 1 << endl;
        cout << n << endl;
        return;
    }
    // print no. of ones + 1
    cout << b.count() + 1 << endl;
    vector<int> ans;
    ans.push_back(n);
    // find highest set bit
    int h = 0;
    for (int i = 0; i < 64; i++) {
        if (b[i]) {
            h = i;
        }
    }
    for (int i = 0; i < h; i++) {
        if(b[i]) {
            ans.push_back(n - (1LL << i));
        }
    }
    ans.push_back((n ^ (ans.back())));
    reverse(ans.begin(), ans.end());
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;
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