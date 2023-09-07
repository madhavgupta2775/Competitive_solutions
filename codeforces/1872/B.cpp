#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long
#define ff first
#define ss second
#define pb push_back

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> v;
    vector<int> reach;
    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        v.pb({x, y});
        reach.pb((y-1)/2 + x);
    }
    sort(reach.begin(), reach.end());
    int ans = reach[0];
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