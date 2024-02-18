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
    int ans = 0;
    forn(i, 0, n) {
        // update ans to the nearest greater multiple of a[i]
        if(ans < a[i]) {
            ans = a[i];
        }
        else {
            int lp = 1, rp = 1e9;
            // binary search to find the nearest greater multiple of a[i]
            while(lp < rp) {
                int mid = (lp + rp) / 2;
                if(mid * a[i] > ans) {
                    rp = mid;
                }
                else {
                    lp = mid + 1;
                }
            }
            ans = lp * a[i];
        }
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