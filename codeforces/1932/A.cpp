#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long
#define ull unsigned long long

const int MOD = 998244353;

void solve() {
    int n; cin >> n;
    vector<char> a(n); forn(i, 0, n) cin >> a[i];
    int ans = 0;
    forn(i, 0, n) {
        if(a[i] == '*') {
            break;
        }
        if(a[i] == '@') {
            ans++;
        }
        if(i < n-1 && a[i+1] == '*') {
            i++;
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