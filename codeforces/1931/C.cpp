#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long
#define ull unsigned long long

const int MOD = 998244353;

void solve() {
    int n; cin >> n;
    vector<int> a(n); forn(i, 0, n) cin >> a[i];
    int lp = 0, rp = n - 1;
    int ans = 0;
    forn(i, 0, n) {
        if(a[i] == a[0]) {
            lp++;
        }
        else {
            break;
        }
    }
    for(int i = n - 1; i >= 0; i--) {
        if(a[i] == a[0] && i != lp) {
            rp--;
        }
        else {
            break;
        }
    }
    ans = max(0ll, rp - lp + 1);
    lp = 0, rp = n - 1;
    forn(i, 0, n) {
        if(a[i] == a[n-1]) {
            lp++;
        }
        else {
            break;
        
        }
    }
    for(int i = n - 1; i >= 0; i--) {
        if(a[i] == a[n-1] && i != lp) {
            rp--;
        }
        else {
            break;
        }
    }
    ans = min(ans, max(0ll, rp - lp + 1));
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
