#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long
#define ull unsigned long long

const int MOD = 998244353;

void solve() {
    int n; cin >> n;
    vector<int> a(n); 
    map<int, int> mp;
    forn(i, 0, n) {
        cin >> a[i];
        a[i] += i+1;
        mp[a[i]]++;
    }
    int curr = 1e18;
    vector<int> ans;
    for(auto it = mp.rbegin(); it != mp.rend(); it++) {
        curr = min(curr, it->first);
        for(int i = 0; i < it->second; i++) {
            ans.push_back(curr);
            curr--;
        }
    }
    for(auto x: ans) cout << x << " ";
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