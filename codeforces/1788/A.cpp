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
    int n, a = 0, b = 0; cin >> n;
    vector<int> v(n);
    forn(i, 0, n){
        cin >> v[i];
        if(v[i] == 2){
            a++;
        }
    }
    forn(i, 0, n-1){
        if(v[i] == 2){
            a--; b++;
        }
        if(a == b){
            cout << i+1 << endl; return;
        }
    }
    cout << -1 << endl;
}   
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        solve(); 
    }
    //solve();
    return 0;
}