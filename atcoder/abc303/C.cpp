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
    int n, m, h, k, x = 0, y = 0; cin >> n >> m >> h >> k;
    string s; cin >> s;
    // vector<pair<int, int>> v(m);
    map<pair<int,int>, bool> ma;
    forn(i, 0, m){
        cin >> x >> y;
        ma[{x, y}] = true;
    }
    // sort(v.begin(), v.end());
    x = 0; y = 0;
    forn(i, 0, n){
        if(s[i] == 'U'){
            y++;
        }
        else if(s[i] == 'D'){
            y--;
        }
        else if(s[i] == 'R'){
            x++;
        }
        else{
            x--;
        }
        h--;
        if(h < 0){
            cout << "No" << endl;
            return;
        }
        if(ma[{x, y}] && h < k){
            h = k;
            ma[{x, y}] = false;
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