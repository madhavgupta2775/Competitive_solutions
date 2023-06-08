#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long
#define ff first
#define ss second

// const int MOD2 = 1e9+7;
// const int MOD = 998244353;


void solve() {
    int n, k; cin >> n >> k;
    // find power of 2 just greater than n
    int p = 1, ans = 0;
    while(p <= n) {
        p *= 2;
        ans++;
    }
    if(k < ans) {
        cout << (1 << k) << endl;
    }
    else{
        cout << n+1 << endl;
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