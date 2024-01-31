#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    int back = 1e18, front = 1;
    vector<int> v;
    forn(i, 0, n) {
        int a, x; cin >> a >> x;
        if(a == 1) {
            front = max(front, x);
        }
        else if(a == 2) {
            back = min(back, x + 1);
        }
        else {
            v.push_back(x);
        }
    }
    int ans = back - front;
    for(auto x: v) {
        if(x >= front && x < back) {
            ans--;
        }
    }
    if(ans < 0) {
        cout << 0 << endl;
    }
    else {
        cout << ans << endl;
    }
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