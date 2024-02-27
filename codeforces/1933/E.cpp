#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long
#define ull unsigned long long

const int MOD = 998244353;

void solve() {
    int n; cin >> n;
    vector<int> a(n), prefix_sum(n+1);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        prefix_sum[i+1] = prefix_sum[i] + a[i];
    }
    int q; cin >> q;
    forn(i, 0, q) {
        int l, u; cin >> l >> u;
        l--;
        // find lower bound of prefix_sum[l+1] + u
        int index = upper_bound(prefix_sum.begin(), prefix_sum.end(), prefix_sum[l] + u) - prefix_sum.begin();
        if(index != n+1) {
            if(2 * (u - prefix_sum[index-1] + prefix_sum[l]) >= prefix_sum[index] - prefix_sum[index-1]) {
                cout << max(index, l+1) << " ";
            } else {
                cout << max(l+1, index-1) << " ";
            }
        }
        else {
            cout << n << " ";
        }
    }
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(30);
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        solve();
    }
    return 0;
}