#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long
#define ull unsigned long long

const int MOD = 998244353;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int lp = 0, rp = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') rp++;
    }
    int ans = 1e18;
    if(rp*2 >= n) {
        ans = 0;
    }
    forn(i, 0, n) {
        if(s[i] == '0') {
            lp++;
        }
        else {
            rp--;
        }
        int s1 = 2*lp - i - 1, s2 = 2*rp - n + (i+1);
        if(s1 >= 0 && s2 >= 0) {
            int diff = abs(2*ans - n);
            int diff2 = abs(2*(i+1) - n);
            if(diff2 < diff) {
                ans = i+1;
            }
        }
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