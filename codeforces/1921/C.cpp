#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

const int mod = 1e9+7;

void solve() {
    int n, f, a, b; cin >> n >> f >> a >> b;
    vector<int> v(n);
    forn(i,0,n) cin >> v[i];
    int time = 0;
    forn(i, 0, n) {
        if(f > min(a*(v[i]-time), b)) {
            f -= min(a*(v[i]-time), b);
            time = v[i];
        } else {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << setprecision(30);
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        solve();
    }
    return 0;
}