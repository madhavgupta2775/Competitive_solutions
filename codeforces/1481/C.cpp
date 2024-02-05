#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

const int MOD = 1e9 + 7;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n), b(n), c(m);
    vector<vector<int>> to_be_painted(n), paints(n);
    forn(i, 0, n) cin >> a[i];
    forn(i, 0, n) {
        cin >> b[i];
        if(b[i] != a[i]) {
            to_be_painted[b[i]-1].push_back(i);
        }
        paints[b[i]-1].push_back(i);
    }
    forn(i, 0, m) cin >> c[i];
    int index = 0;
    vector<int> ans(m, 0);
    for(int i = 0; i < m; i++) {
        if(to_be_painted[c[i]-1].size() > 0) {
            while(index <= i) {
                ans[index] = to_be_painted[c[i]-1].back() + 1;
                index++;
            }
            to_be_painted[c[i]-1].pop_back();
        }
        if(paints[c[i]-1].size() > 0) {
            while(index <= i) {
                ans[index] = paints[c[i]-1].back() + 1;
                index++;
            }
        }
    }
    if(index < m) {
        cout << "NO" << endl;
        return;
    }
    for(int i = 0; i < n; i++) {
        if(to_be_painted[i].size() > 0) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    for(int i = 0; i < m; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
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