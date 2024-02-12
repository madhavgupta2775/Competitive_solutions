#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long
#define ull unsigned long long

const int MOD = 998244353;

void solve() {
    int n; cin >> n;
    int ans = 0, m_idx = 0;
    vector<int> a(n), m_val(n); 
    forn(i, 0, n) {
        cin >> a[i];
        if(i == 0) {
            m_val[0] = a[i]+1; continue;
        }
        m_val[i] = max(a[i]+1, m_val[i-1]);
    }
    vector<int> marks(n); int curr = m_val[n-1];
    for(int i = n-1; i >= 0; i--) {
        curr = max(curr-1, m_val[i]);
        marks[i] = curr;
    }
    for(int i = 0; i < n; i++) {
        ans += marks[i] - a[i] -1;
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(30);
    int T = 1;
    // cin >> T;
    for(int I = 1; I <= T; I++) {
        solve();
    }
    return 0;
}
