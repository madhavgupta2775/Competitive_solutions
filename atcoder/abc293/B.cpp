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
    vector<pair<int, bool>> v(n+1);
    vector<int> call;
    forn(i, 0, n){
        cin >> v[i+1].first;
        if(v[i+1].second == false) {
            v[v[i+1].first].second = true;
        }
    }
    forn(i, 1, n+1){
        if(v[i].second == false){
            call.push_back(i);
        }
    }
    cout << call.size() << endl;
    forn(i, 0, call.size()){
        cout << call[i] << " ";
    }
    cout << endl;
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