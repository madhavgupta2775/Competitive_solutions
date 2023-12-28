#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

void solve() {
    int n; cin >> n;
    int ans = 0;
    forn(i, 0, n) {
        int x; cin >> x;
        ans += x;
    }
    // if ans is a perfect square then print 1 else 0
    int sq = sqrt(ans);
    if(sq * sq == ans) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
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