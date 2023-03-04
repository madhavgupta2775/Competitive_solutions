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
    double a, b; cin >> a >> b;
    cout << setprecision(30);
    if(b<a){
        swap(a, b);
    }
    double theta = 0, pi = 3.141592653589793238462643383279;
    if(b < 2*a/sqrt(3))theta = min(atan(2*(b/a) - sqrt(3)), pi/6);
    else{
        theta = pi/6;
    }
    cout << a/cos(theta) << endl;
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