#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

const int MOD = 1e9 + 7;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> ans(n);
    int count = INT_MAX;
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        count = min(count, b - a + 1);
    }
    cout << count << endl;
    int curr = 0;
    for(int i = 0; i < n; i++) {
        cout << curr % count << " ";
        curr++;
    }
    cout << endl;
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