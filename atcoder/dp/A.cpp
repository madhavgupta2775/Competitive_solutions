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
int smol(int n, vector<int> &h, vector<int> &mincost){
    if(mincost[n] != -1){
        return mincost[n];
    }
    if(n == 0){
        mincost[n] = 0;
        return mincost[n];
    }
    if(n == 1){
        mincost[n] = abs(h[1] - h[0]);
        return mincost[n];
    }
    mincost[n] = min(smol(n-1, h, mincost) + abs(h[n] - h[n-1]), smol(n-2, h, mincost) + abs(h[n] - h[n-2]));
    return mincost[n];
}

void solve() {
    int n; cin >>n;
    vector<int> h(n), mincost(n, -1);
    forn(i, 0, n){
        cin >> h[i];
    }
    cout << smol(n-1, h, mincost) << endl;
}   
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    // cout << setprecision(30);
    // int T = 1;
    // cin >> T;
    // for(int I = 1; I <= T; I++) {
    //     solve(); 
    // }
    solve();
    return 0;
}