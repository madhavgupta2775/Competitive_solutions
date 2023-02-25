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
    int n; cin >> n;
    vector<int> v(n);
    forn(i, 0, n){
        cin >> v[i];
    }
    forn(i, 0, n){
        for(int j = i+1; j < n; j++){
            if(gcd(v[i], v[j]) < 3){
                cout << "yes" << endl; return;
            }
        }
    }
    cout << "no" << endl;
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