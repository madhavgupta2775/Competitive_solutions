#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long
#define ull unsigned long long

const int MOD = 998244353;


void solve() {
    int n, k, m; cin >> n >> k >> m;
    double ans = 0, curr_avg = 0, curr_sum = 0;
    vector<int> a(n); int kk = k * n;
    forn(i, 0, n) {
        cin >> a[i]; curr_sum += a[i];
    }    
    curr_avg = (curr_sum + min(m, kk)) / n; ans = curr_avg;
    int count = n;
    sort(a.begin(), a.end());
    forn(i, 0, min(m, n-1)) {
        curr_sum -= a[i]; count--; kk -= k;
        curr_avg = (curr_sum + min(m-i-1, kk)) / count;
        ans = max(ans, curr_avg);
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(30);
    int T = 1;
    // cin >> T;
    for(int I = 1; I <= T; I++) {
        solve();
    }
    return 0;
}
