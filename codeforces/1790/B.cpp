#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long

const int MOD2 = 1e9+7;
const int MOD = 998244353;

void solve() {
    int n, s, r; cin >> n >> s >> r;
    int temp = r;
    forn(i, 0, n-1){
        cout << min(s-temp, r-n+i+2) << " ";
        r -= min(s-temp, r-n+i+2);
    }
    cout << s-temp << endl;
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