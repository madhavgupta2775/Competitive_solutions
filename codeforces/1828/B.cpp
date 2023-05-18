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
    int n, ans = 0, temp = 0; cin >> n;
    vector<int> v(n);
    forn(i, 0, n){
        cin >> v[i];
    }
    forn(i, 0, n){
        if(v[i] != i+1){
            ans = gcd(v[i] - i - 1, ans);
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
    return 0;
}