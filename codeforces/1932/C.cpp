#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long
#define ull unsigned long long

const int MOD = 998244353;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n); forn(i, 0, n) cin >> a[i];
    string s; cin >> s;
    int l = 0, r = n-1;
    forn(i, 0, n) {
        if(s[i] == 'L') {
            l++;
        }
        else {
            r--;
        }
    }
    l--; r++;
    vector<int> b; int ans = 1;
    for(int i = n-1; i >= 0; i--) {
        if(s[i] == 'L') {
            ans = (ans * (a[l] % m)) % m;
            b.push_back(ans);
            l--;
        }
        else {
            ans = (ans * (a[r] % m)) % m;
            b.push_back(ans);
            r++;
        }
    }
    reverse(b.begin(), b.end());
    for(auto x : b) {
        cout << x << " ";
    }
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