#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long
 
const int MAXN = 200100;
const int MOD = 998244353;
 
void solve() {
    int n, sum = 1, a = 1; string s; 
    cin >> n >> s;
    forn(i, 1, n){
        if(s[i] == s[i-1]){
            a<<=1; a %= MOD;
        }
        else{
            a = 1;
        }
        sum += a;
        sum%=MOD;
    }
    cout << sum << endl;
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