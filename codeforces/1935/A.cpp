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
    string r = s; reverse(r.begin(), r.end());
    string t = r + s;
    forn(i, 0, s.size()) {
        if(s[i] > t[i]) {
            cout << t << endl;
            return;
        }
        else if(s[i] < t[i]) {
            cout << s << endl;
            return;
        }
    }
    cout << s << endl;
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