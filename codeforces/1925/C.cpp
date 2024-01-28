#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

const int MOD = 1e9 + 7;

void solve() {
    int n, k, m; cin >> n >> k >> m;
    string s; cin >> s;
    vector<bool> v(k, false);
    int cnt = 0; string ans = "";
    forn(i, 0, m) {
        if(!v[s[i] - 'a']) {
            v[s[i] - 'a'] = true;
            cnt++;
        }
        if(cnt == k) {
            ans += s[i];
            v.assign(k, false);
            cnt = 0;
        }
    }
    if(ans.size() < n) {
        forn(i, 0, k) {
            if(!v[i]) {
                while(ans.size() < n) {
                    ans += (char)(i + 'a');
                }
                break;
            }
        }
        cout << "NO" << endl;
        cout << ans << endl;
    }
    else {
        cout << "YES" << endl;
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