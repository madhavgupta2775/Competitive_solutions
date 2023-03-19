#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long
#define ff first
#define ss second

const int MOD2 = 1e9+7;
const int MOD = 998244353;

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n, ans = 0, temp = 0; cin >> n;
    vector<int> v(2*n);
    forn(i, 0, 2*n){
        cin >> v[i];
        ans += abs(v[i]);
    }
    sort(v.begin(), v.end());
    if(n == 1){
        ans = min(ans, abs(v[1] - v[0]));
    }
    else if(n == 2){
        ans = min(ans,abs(v[0] + 1) + abs(v[1] + 1) + abs(v[2] + 1) + abs(v[3] - 2)); 
        ans = min(ans, abs(v[0] - 2) + abs(v[1] - 2) + abs(v[2] - 2) + abs(v[3] - 2));
    }
    else if(n % 2 == 0){
        forn(i, 0, 2*n-1){
            temp += abs(v[i] + 1);
        }
        temp += abs(v[2*n-1] - n);
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