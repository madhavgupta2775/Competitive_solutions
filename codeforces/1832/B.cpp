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
    int n, k, sum = 0, minn = 0; cin >> n >> k;
    vector<int> v(n), sums(n+1), dumm(n+1);
    forn(i, 0, n){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    forn(i, 0, n){
        sums[i+1] = sums[i] + v[i];
        dumm[i+1] = sums[i+1];
    }
    forn(i, 0, k+1){
        minn = max(minn, sums[n-k+i] - sums[2*i]);
    }
    cout << minn << endl;
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