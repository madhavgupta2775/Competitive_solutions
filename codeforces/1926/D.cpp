#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long
#define ull unsigned long long

const int MOD = 998244353;

// comparator function for sorting bitset
bool cmp(bitset<31> a, bitset<31> b) {
    int x = a.to_ulong();
    int y = b.to_ulong();
    return x < y;
}

void solve() {
    int n; cin >> n;
    map<bitset<31>, int, decltype(cmp)*> mp(cmp);
    int ans = 0;
    forn(i, 0, n) {
        int x; cin >> x;
        bitset<31> b(x);
        // find inverse of b
        bitset<31> inv = ~b;
        if(mp[inv] > 0) {
            mp[inv]--;
            ans++;
        } else {
            mp[b]++;
        }
    }
    for(auto it: mp) {
        ans += it.second;
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