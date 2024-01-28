#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

const int MOD = 1e9 + 7;

void solve() {
    int n, k, d; cin >> n >> k >> d;
    vector<int> a(n); forn(i,0,n) cin >> a[i];
    vector<int> v(k); forn(i,0,k) cin >> v[i];
    int ans = 0;
    forn(i, 0, min(2*n, d)) {
        int temp = (d-i-1)/2;
        for(int j = 0; j < n; j++) {
            if(a[j] == j+1) temp++;
        }
        ans = max(ans, temp);
        for(int j = 0; j < v[i%k]; j++) {
            a[j]++;
        }
    }
    cout << ans << endl;
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