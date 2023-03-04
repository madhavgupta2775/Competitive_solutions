#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long
#define ff first
#define ss second

const int MOD2 = 1e9+7;
const int MOD = 998244353;
int sum = 0;
void dfs(int i, int s, vector<bool> &visited, vector<vector<int>> &adj, vector<vector<int>> &mat) {
    if (visited[s]) return;
    visited[s] = true;
    if(mat[i][s] != 1 && i != s){
        sum++; mat[i][s] = 1;
    }
    // process node s
    for (auto u: adj[s]) {
        dfs(i, u, visited, adj, mat);
    }
}

void solve() {
    int n, m, a, b;cin >> n >> m;
    vector<vector<int>> adj(n+1), mat(n+1, vector<int> (n+1));
    forn(i, 0, m){
        cin >> a >> b;
        adj[a].push_back(b);
        mat[a][b] = 1;
    }
    forn(i, 1, n+1){
        if(adj[i].size() != 0){
            vector<bool> visited(n+1, false);
            dfs(i, i, visited, adj, mat);
        }
    }
    cout << sum << endl;
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