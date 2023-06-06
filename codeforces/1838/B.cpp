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
    int n, twoi, onei, maxi; cin >> n;
    vector<int> a(n);
    forn(i, 0, n){
        cin >> a[i];
        if(a[i] == 2) twoi = i;
        if(a[i] == 1) onei = i;
        if(a[i] == n) maxi = i;
    }
    if((maxi < onei && maxi > twoi) || (maxi > onei && maxi < twoi)){
        cout << onei + 1 << " " << twoi + 1 << endl;
        return;
    }
    else{
        if(maxi < onei && maxi < twoi){
            cout << maxi + 1 << " " << min(twoi + 1, onei+1) << endl;
            return;
        }
        else{
            cout << maxi + 1 << " " << max(onei + 1, twoi+1) << endl;
            return;
        }
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