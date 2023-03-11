#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long
#define ff first
#define ss second

const int MOD2 = 1e9+7;
const int MOD = 998244353;
int path(vector<vector<int>> &v, int i, int j, set<int> &m){
    int sum = 0;
    if(m.find(v[i][j]) != m.end()){
        //m.erase(v[i][j]);
        return 0;
    }
    m.insert(v[i][j]);
    if(i == v.size()-1 && j == v[i].size()-1){
        m.erase(v[i][j]);
        return 1;
    }
    if(i < v.size()-1){
        sum += path(v, i+1, j, m);
    }
    if(j < v[i].size()-1){
        sum += path(v, i, j+1, m);
    }
    m.erase(v[i][j]);
    return sum;
}

void solve() {
    int h, w; cin >> h >> w;
    vector<vector<int>> v(h, vector<int>(w));
    set<int> m;
    forn(i, 0, h){
        for(int j = 0; j < w; j++){
            cin >> v[i][j];
        }
    }
    cout << path(v, 0, 0, m) << endl;
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