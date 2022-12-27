#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long
 
const int MAXN = 200100;
const int MOD = 1e9+7;
 
void solve() {
    int n, a = 0, b = 1; cin >>n;
    b = n; n--;
    int ans = 0;
    a = (n*(n+1)/2);
    ans += a%MOD;
    ans += (b*b)%MOD; 
    if(a%3==0){
        a /= 3;a%=MOD; a*= 2*(2*n+1)%MOD;
    }
    else{
        a%=MOD;
        a *= 2*((2*n+1)/3)%MOD;
    }
    ans += a; ans %= MOD;
    ans *= 2022;
    ans %= MOD;
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