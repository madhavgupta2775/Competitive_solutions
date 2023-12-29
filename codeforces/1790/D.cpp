#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

void solve() {
    int n; cin >> n;
    map<int, int> mp;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        mp[x]++;
    }
    int ans = 0, prev = 0, cnt = 0;
    for(auto x: mp) {
        if(cnt == 0) {
            cnt = x.second;
        }
        else {
            if(x.first == prev + 1) {
                ans += max(0LL, cnt - x.second);
                cnt = x.second;
            }
            else {
                ans += cnt;
                cnt = x.second;
            }
        }
        prev = x.first;
    }
    if(cnt != 0) {
        ans += cnt;
    }
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