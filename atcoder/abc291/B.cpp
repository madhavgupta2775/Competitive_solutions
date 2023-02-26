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
    int n, sum = 0; cin >> n;
    vector<int> v(n*5);
    forn(i, 0, 5*n){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    forn(i, n, 4*n){
        sum += v[i];
    }
    cout << setprecision(13) << endl;
    cout << sum/double(3*n) << endl;
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