#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long
 
const int MOD2 = 1e9+7;
const int MOD = 998244353;

void solve() {
    int n, sum = 0, ans = 1; cin >>n;
    vector<int> v(n), psum(n);
    forn(i, 0, n){
        cin >> v[i];
        sum += v[i];
        psum[i] = sum;
    }
    forn(i, 0, n-1){
        if(gcd(sum, psum[i])!=1){
            ans = max(gcd(sum, psum[i]), ans);
        }
    }
    cout << ans << endl;
}   
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        solve(); 
    }
    return 0;
}