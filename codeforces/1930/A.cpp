#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long
#define ull unsigned long long

const int MOD = 998244353;


void solve() {
    int n; cin >> n;
    vector<int> a(2*n); forn(i, 0, 2*n) cin >> a[i];
    sort(a.begin(), a.end());
    int ans = 0;
    for(int i = 0; i < 2*n; i+= 2) {
        ans += a[i];
    }
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
