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
    int n; cin >>n ;
    string s; cin >> s;
    int ans = INT_MAX, temp = 0;
    forn(i, 0, 26){
        temp = 0;
        for(int j = 0; j < n; j++){
            temp += abs(s[j] - 'a' - i);
        }
        ans = min(ans, temp);
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
    // solve();
    return 0;
}