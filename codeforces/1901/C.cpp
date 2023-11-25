#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

void solve() {
    int n; cin >> n;
    int minn = INT_MAX, maxx = INT_MIN;
    forn(i,0,n) {
        int x; cin >> x;
        minn = min(minn, x);
        maxx = max(maxx, x);
    }
    int ans = 0;
    vector<int> v;
    while(minn != maxx) {
        if(minn % 2 && maxx % 2 == 0) {
            v.push_back(1);
            minn++; maxx++;
        }
        else {
            v.push_back(0);
        }
        minn /= 2; maxx /= 2;
        ans++;
    }
    cout << ans << endl;
    if(ans > n) return;
    forn(i,0,v.size()) {
        cout << v[i] << " ";
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