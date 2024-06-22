#include <bits/stdc++.h>
using namespace std;

#define endl "\n" 
#define int long long

const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    int a = 0;
    for (int i = 0; i < n; i++) {
        string temp; cin >> temp;
        if(temp == "Takahashi") a++;
    }
    cout << a << endl;
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
