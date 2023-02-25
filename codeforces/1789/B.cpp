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
    int n; cin >> n;
    int l = 0, r = 0;
    bool t = true;
    string s; cin >> s;
    forn(i, 0, n/2){
        if(s[i] != s[n-i-1]){
            l = i; r = i; break;
        }
    }
    forn(i, l, n/2){
        if(s[i] != s[n-i-1] && t){
            r = i;
        }
        else if(s[i] == s[n-i-1]){
            t = false;
        }
        else{
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}   
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        solve(); 
    }
    //solve();
    return 0;
}