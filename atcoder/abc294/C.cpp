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
    int n, m; cin >> n >>  m;
    vector<int> one(n), two(m), ans(n+m);
    map<int, int> mm;
    forn(i, 0, n){
        cin >> one[i];
        ans[i] = one[i];
    }
    forn(i, 0, m){
        cin >> two[i];
        ans[n+i] = two[i];
    }
    sort(ans.begin(), ans.end());
    forn(i, 0, n+m){
        mm[ans[i]] = i + 1;
    }
    forn(i, 0, n){
        cout << mm[one[i]] << " ";
    }
    cout << endl;
    forn(i, 0, m){
        cout << mm[two[i]] << " ";
    }
    cout << endl;
}   
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    // int T = 1;
    // cin >> T;
    // for(int I = 1; I <= T; I++) {
    //     solve(); 
    // }
    solve();
    return 0;
}