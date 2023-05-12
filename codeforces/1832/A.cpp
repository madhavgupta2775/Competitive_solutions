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
    int ch = 1;
    forn(i, 0, s.size()/2){
        if(s[i] != s[0]){
            ch++; break;
        }
    }
    if(ch == 1){
        cout << "NO" << endl;
    }
    else{
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