#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long
#define ull unsigned long long

const int MOD = 998244353;


void solve() {
    int n, x, y; cin >> n >> x >> y;
    int ans = 0; 
    vector<int> a(n);
    map<pair<int, int>, int> mp;
    forn(i, 0, n) {
        cin >> a[i];
        mp[{a[i] % x, a[i] % y}]++;
    }
    forn(i, 0, n) {
        ans += mp[{(x - a[i] % x) % x, (a[i] % y)}];
        if((x - a[i] % x) % x == a[i] % x) {
            ans--;
        }
    }
    ans /= 2;
    cout << ans << endl;
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
