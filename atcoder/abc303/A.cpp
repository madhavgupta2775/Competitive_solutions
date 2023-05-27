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
    int n; cin >> n;
    string a, b; cin >> a >> b;
    forn(i, 0, n){
        if(a[i] != b[i]){
            if((a[i] == '1' && b[i] == 'l') || (a[i] == 'l' && b[i] == '1')){
                continue;
            }
            else if((a[i] == '0' && b[i] == 'o') || (a[i] == 'o' && b[i] == '0')){
                continue;
            }
            else{
                cout << "No" << endl;
                return;
            }
        }   
    }
    cout << "Yes" << endl;
}   
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    // cout << setprecision(30);
    int T = 1;
    // cin >> T;
    for(int I = 1; I <= T; I++) {
        solve(); 
    }
    return 0;
}