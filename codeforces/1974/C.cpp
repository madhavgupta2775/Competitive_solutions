#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

const int MOD = 1e9 + 7;

int encode(int a, int b) {
    return a * 1e6 + b;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n); forn(i, 0, n) cin >> a[i];
    map<int, int> m1, m2, m3;
    map<pair<int, pair<int, int>>, int> mp;
    for(int i = 0; i < n-2; i++) {
        mp[{a[i], {a[i+1], a[i+2]}}]++;
        m1[encode(a[i], a[i+1])]++;
        m2[encode(a[i], a[i+2])]++;
        m3[encode(a[i+1], a[i+2])]++;
    }
    int ans = 0;
    forn(i, 0, n-2) {
        int temp = m1[encode(a[i], a[i+1])] + m2[encode(a[i], a[i+2])] + m3[encode(a[i+1], a[i+2])] - 3*mp[{a[i], {a[i+1], a[i+2]}}];
        ans += temp;
    }
    cout << ans/2 << endl;
}


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << fixed << setprecision(30);
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        solve();
    }
    return 0;
}