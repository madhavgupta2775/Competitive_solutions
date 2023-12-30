#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

void solve() {
    int n, k; cin >> n >> k;
    int ans = 2023;
    vector<int> v(n);
    forn(i, 0, n) {
        cin >> v[i];
    }
    forn(i, 0, n) {
        if(ans % v[i] != 0) {
            cout << "NO" << endl;
            return;
        }
        ans /= v[i];
    }
    if(k > 0) cout << "YES" << endl;
    else {
        cout << "NO" << endl;
        return;
    }
    cout << ans << " ";
    forn(i, 0, k-1) {
        cout << 1 << " ";
    }
    cout << endl;
}

 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    // cout << setprecision(30);
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        solve();
    }
    return 0;
}