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
    int m, n, temp; cin >> m;
    vector<int> ans(m);
    map<int, int> pp;
    forn(i, 0, m){
        cin >> n;
        for(int j = 0; j < n; j++){
            cin >> temp;
            pp[temp] = i;
        }
    }
    for(auto a : pp){
        ans[a.ss] = a.ff;
    }
    forn(i, 0, m){
        if(ans[i] == 0){
            cout << -1 << endl; return;
        }
    }
    forn(i, 0, m){
        cout << ans[i] << " ";
    }
    cout << endl;
}   
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    // cout << setprecision(30);
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        solve(); 
    }
    return 0;
}