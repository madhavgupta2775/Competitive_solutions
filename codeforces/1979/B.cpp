#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

const int MOD = 1e9 + 7;

void solve() {
    int x, y; cin >> x >> y;
    bitset<63> a(x), b(y);
    // find lowest bit where a and b differ
    int ans = 0;
    for(int i = 0; i < 63; i++) {
        if(a[i] != b[i]) {
            ans = (1LL << i);
            break;
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
