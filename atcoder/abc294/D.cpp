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
    int n, q, a, b, ind = 1, count = 1; cin >> n >> q;
    vector<int> v(n+1), ans;
    forn(i, 0, q){
        cin >> a;
        if(a == 1){
            v[ind] = 1;
            ind++;
        }
        if(a == 2){
            cin >> b;
            v[b] = -1;
        }
        if(a == 3){
            while(v[count] != 1){
                count++;
            }
            ans.push_back(count);
        }
    }
    forn(i, 0, ans.size()){
        cout << ans[i] << endl;
    }
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