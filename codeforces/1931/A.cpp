#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long
#define ull unsigned long long

const int MOD = 998244353;

void solve() {
    int x; cin >> x;
    vector<char> ans(3);
    for(int i = 2; i >= 0; i--) {
        int val = max(1ll, min(x - i, 26ll));
        x -= val;
        ans[i] = 'a' + val - 1;
    }
    for(auto c : ans) cout << c;
    cout << endl;
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
