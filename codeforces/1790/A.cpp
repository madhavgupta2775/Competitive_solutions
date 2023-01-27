#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long

const int MOD2 = 1e9+7;
const int MOD = 998244353;

void solve() {
    string s, pi = "3141592653589793238462643383279";
    cin >> s;
    forn(i, 0, s.size()){
        if(s[i] != pi[i]){
            cout << i << endl;
            return;
        }
    }
    cout << s.size() << endl;
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