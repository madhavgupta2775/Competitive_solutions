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
    int n, a = 0, b = 0, c = 0, d = 0; cin >> n;
    if(n%2){
        cout << "YES" << endl;
        a = 1, b = 2*n-1; c = n; d = n+1;
        forn(i, 1, n+1){
            if(i%2){
                cout << c << " " << d << endl;
                c--; d += 2;
            }
            else{
                cout << a << " " << b << endl;
                a++; b-=2;
            }
        }
    }
    else{
        cout << "NO" << endl;
    }
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