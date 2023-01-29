#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long

const int MOD2 = 1e9+7;
const int MOD = 998244353;

void solve() {
    int n; cin >> n;
    if(n%2){
        cout << -1 << endl;
    }
    else{
        cout << 1 << " " << n/2 << endl;
    }
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