#include <bits/stdc++.h>
using namespace std;

#define endl "\n" 
#define int long long

const int MOD = 998244353;

void solve() {
    int x1, y1; cin >> x1 >> y1;
    int x2, y2; cin >> x2 >> y2;
    if(x1 > y1 && x2 <= y2) {
        cout << "NO" << endl;
    }
    else if(x1 < y1 && x2 >= y2) {
        cout << "NO" << endl;
    }
    else if(x1 == y1 && x2 == y2) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
    }
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
