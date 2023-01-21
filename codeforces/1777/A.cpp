#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long
 
const int MOD2 = 1e+7;
const int MOD = 998244353;

void solve() {
    int n, moves = 0; cin >> n;
    vector<int> v(n);
    forn(i, 0, n){
        cin >> v[i];
    }
    forn(i, 1, n){
        if(v[i]%2 == v[i-1]%2){
            moves++;
        }
    }
    cout << moves << endl;
}   
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        solve(); 
    }
    return 0;
}