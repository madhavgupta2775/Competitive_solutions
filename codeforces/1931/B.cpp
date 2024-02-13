#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long
#define ull unsigned long long

const int MOD = 998244353;

void solve() {
    int n, avg = 0; cin >> n;
    vector<int> a(n); forn(i, 0, n) {
        cin >> a[i];   avg += a[i];
    }
    avg /= n; // avg is divisible by n
    int diff = 0;
    for(int i = n-1; i >= 0; i--) {
        diff += a[i] - avg;
        if(diff > 0) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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
