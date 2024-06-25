#include <bits/stdc++.h>
using namespace std;

#define endl "\n" 
#define int long long

const int MOD = 998244353;

void solve() {
    int n, l, r; cin >> n >> l >> r;
    vector<int> a(n); for (int &i : a) cin >> i;
    int ans = 0, sum = 0;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        sum += a[i]; q.push(a[i]);
        if(sum >= l && sum <= r) {
            ans++; sum = 0; q = queue<int>();
        }
        else if(sum > r) {
            while(!q.empty() && sum > r) {
                sum -= q.front();
                q.pop();
                if(sum >= l && sum <= r) {
                    ans++; sum = 0; q = queue<int>();
                }
            }
        }
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
