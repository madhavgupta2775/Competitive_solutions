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
    int n, x = 0, y = 0; cin >> n;
    string s; cin >> s;
    map<pair<int, int>, bool> m;
    m[{0,0}] = true;
    forn(i, 0, n){
        if(s[i] == 'R'){
            x++;
        }
        else if(s[i] == 'L'){
            x--;
        }
        else if(s[i] == 'U'){
            y++;
        }
        else{
            y--;
        }
        if(m[{x, y}]){
            cout << "Yes" << endl; return;
        }
        else{
            m[{x, y}] = true;
        }
    }
    cout << "No" << endl;
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