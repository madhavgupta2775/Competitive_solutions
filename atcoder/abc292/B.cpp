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
    int n, q, t, x; cin >> n >> q;
    vector<int> v(n+1);
    forn(i, 0, q){
        cin >> t >> x;
        if(t == 1){
            v[x]++;
        }
        else if(t == 2){
            v[x] += 2;
        }
        else{
            if(v[x] > 1){
                cout << "Yes" << endl;
            }
            else{
                cout << "No" << endl;
            }
        }
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