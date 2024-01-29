#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<int> p(n), b(n);
    forn(i, 0, n) {
        cin >> p[i];
        p[i]--;
    }
    int ans = 0;
    forn(i, 0, n) {
        cin >> b[i];
        ans += b[i];
    }
    int comps = 0;
    vector<bool> vis(n, false);
    vector<int> max_elem;
    forn(i, 0, n) {
        if(!vis[i]) {
            int j = i;
            comps++;
            max_elem.push_back(p[j]);
            while(!vis[j]) {
                max_elem.back() = max(max_elem.back(), p[j]);
                vis[j] = true;
                j = p[j];
            }
        }
    }
    ans = (ans % 2)^1;
    if(comps == 1) {
        cout << ans << endl;
        return;
    }
    else {
        cout << ans + comps << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    // cout << setprecision(30);
    int T = 1;
    // cin >> T;
    for(int I = 1; I <= T; I++) {
        solve();
    }
    return 0;
}