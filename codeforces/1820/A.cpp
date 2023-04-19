#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long
#define ff first
#define ss second

const int MOD2 = 1e9+7;
const int MOD = 998244353;

void solve() {
    string s; cin >> s;
    int ans = 0;
    if(s == "^"){
        cout << 1 << endl; return;
    }
    if(s == "_"){
        cout << 2 << endl; return;
    }
    forn(i, 0, s.size()){
        if(s[i] == '_'){
            if(i == 0 || s[i-1] == '_'){
                ans++;
            }
            if(i == s.size() -1){
                ans++;
            }
        }
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
    // solve();
    return 0;
}