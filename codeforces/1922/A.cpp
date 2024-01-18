#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

const int mod = 1e9 + 7;

void solve() {
    int n; cin >> n;
    string a, b, c;
    cin >> a >> b >> c;
    forn(i, 0, n) {
        if(a[i] == b[i]) {
            if(a[i] != c[i]) {
                cout << "YES" << endl;
                return;
            }
        }
        else {
            if(a[i] != c[i] && b[i] != c[i]) {
                cout << "YES" << endl;
                return;
            }

        }
    }
    cout << "NO" << endl;
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