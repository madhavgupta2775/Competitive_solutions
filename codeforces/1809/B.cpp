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
int knap(int n, int w, vector<int> &v, vector<pair<int, int>> &weights, vector<int> &mem){
    if(mem[w] != -1){
        return mem[w];
    }
    if(w == 0){
        mem[0] = 0;
        return mem[0];
    }
    forn(i, 0, n){
        if(w >= weights[i].first && weights[i].second != true){
            weights[i].second = true;
            mem[w] = max(knap(n, w- weights[i].first, v, weights, mem) + v[i], mem[w]);
            weights[i].second = false;
        }
    }
    mem[w] = max(0ll, mem[w]);
    return mem[w];
}   

void solve() {
    // int n, w, ans = 0; cin >> n >> w;
    // vector<int> v(n);
    // vector<int> mem(w+1, -1);
    // vector<pair<int, int>> weights(n, {0, false});
    // forn(i, 0, n){
    //     cin >> weights[i].first >> v[i];
    // }
    // cout << knap(n, w, v, weights, mem) << endl;
    int n; long double num; cin >> num;
    n = sqrt(num);
    if(n*n == round(num)){
        cout << n-1 << endl;
    }
    else{
        cout << n << endl;
    }
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
    // solve();
    return 0;
}