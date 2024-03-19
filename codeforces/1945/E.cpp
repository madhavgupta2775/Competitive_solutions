#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long
#define ull unsigned long long

const int MOD = 998244353;

void solve() {
    int n, x; cin >> n >> x;
    vector<int> p(n); forn(i, 0, n) cin >> p[i];
    int l = 0, r = n, m = (l + r) / 2;
    int index = -1;
    forn(i, 0, n) {
        if(p[i] == x) {
            index = i;
            break;
        }
    }
    while(r - l > 1) {
        m = (l + r) / 2;
        if(p[m] <= x) l = m;
        else r = m;
    }
    if(l != index) {
        cout << 1 << endl;
        if(l > index) swap(l, index);
        cout << l + 1 << " " << index + 1 << endl;
    }
    else {
        cout << 0 << endl;
    }
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