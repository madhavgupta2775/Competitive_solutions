#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

const int mod = 1e9+7;

void solve() {
    vector<pair<int, int>> a;
    forn(i, 0, 4) {
        int x, y; cin >> x >> y;
        a.push_back({x, y});
    }
    sort(a.begin(), a.end());
    int l = a[1].second - a[0].second, b = a[2].first - a[0].first;
    cout << l*b << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << setprecision(30);
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        solve();
    }
    return 0;
}