#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long
#define ff first
#define ss second

// const int MOD2 = 1e9+7;
// const int MOD = 998244353;

void solve() {
    int n, k, l, t1, t2, sum = 0; cin >> n >> k >> l;
    vector<int> v;
    forn(i, 0, n){
        cin >> t1 >> t2;
        if(t2 == l){
            v.push_back(t1);
        }
    }

    sort(v.begin(), v.end());
    // cout << v.size() << " " << k << endl;
    for(int j = v.size()-1; j >= max(0ll, int64_t(v.size())-k); j--){
        sum += v[j];
    }
    if(v.size() < k){
        cout << -1 << endl; return;
    }
    cout << sum << endl;

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