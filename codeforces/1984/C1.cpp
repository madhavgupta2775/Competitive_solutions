#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<int> a(n); forn(i, 0, n) cin >> a[i];
    int ans = 0;
    int max_num = 0, min_num = 0;
    for (int i = 0; i < n; i++) {
        if(a[i] >= 0) {
            max_num = max(max_num + a[i], abs(min_num + a[i]));
            min_num += a[i];
        }
        else {
            max_num = max(abs(max_num + a[i]), abs(min_num + a[i]));
            min_num += a[i];
        }
    }   
    cout << max_num << endl;
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
