#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long
#define ff first
#define ss second
#define pb push_back

// const int MOD2 = 1e9+7;
// const int MOD = 998244353;


void solve() {
    int n, m, h; cin >> n >> m >> h;
    vector<int> carcapacity(n), outletpower(m);
    forn(i, 0, n){
        cin >> carcapacity[i];
    }
    forn(i, 0, m){
        cin >> outletpower[i];
        outletpower[i] *= h;
    }
    sort(carcapacity.begin(), carcapacity.end(), greater<int>());
    sort(outletpower.begin(), outletpower.end(), greater<int>());
    int ans = 0;
    forn(i, 0, min(n, m)){
        ans += min(carcapacity[i], outletpower[i]);
    }
    cout << ans << endl;
}   
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << setprecision(30);
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        solve(); 
    }
    return 0;
}