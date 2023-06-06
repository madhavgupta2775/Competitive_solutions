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
    int n, ans = 0, maxi = 0; cin >> n;
    vector<int> a(n);
    forn(i,0,n){
        cin >> a[i];
        if(a[i] < 0){
            ans = a[i];
        }
        maxi = max(maxi, a[i]);
    }
    if(ans){
        cout << ans << endl;
    }
    else{
        cout << maxi << endl;
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