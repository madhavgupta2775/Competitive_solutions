#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> v(n);
    forn(i, 0, n) {
        cin >> v[i].first;
    }
    forn(i, 0, n) {
        cin >> v[i].second;
    }
    sort(v.begin(), v.end());
    forn(i, 0, n) {
        cout << v[i].first << " ";
    }
    cout << endl;
    forn(i, 0, n) {
        cout << v[i].second << " ";
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