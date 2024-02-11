#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

const int MOD = 998244353;

void solve() {
    int n; cin >> n;
    set<int> s;
    vector<int> a; forn(i, 0, n) {
        int x; cin >> x;
        if(s.find(x) == s.end()) {
            a.push_back(x);
            s.insert(x);
        }
    }
    sort(a.begin(), a.end());
    int ans = 0, lp = 0, rp = 0;
    while(lp < a.size()) {
        while(rp < a.size() && a[rp] - a[lp] < n) rp++;
        ans = max(ans, rp - lp);
        lp++;
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
