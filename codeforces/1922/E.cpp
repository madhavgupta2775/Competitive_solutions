#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

void solve() {
    int x; cin >> x;
    int len = 0, temp = x;
    while(temp > 1) {
        temp /= 2;
        len++;
    }
    vector<int> ans;
    forn(i, 0, len) {
        ans.push_back(i);
    }
    for(int i = len-1; i >= 0; i--) {
        if((1ll << i) & x) {
            ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    for(auto it: ans) {
        cout << it << " ";
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