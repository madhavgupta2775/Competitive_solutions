#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

int dp[100005];

int dfs(int u, vector<vector<int>> &adj) {
    if(dp[u] != -1) return dp[u];
    int ans = 0;
    for(int v : adj[u]) {
        ans = max(ans, dfs(v, adj));
    }
    ans++; dp[u] = ans;
    return ans;
}


void solve() {
    int n, m; cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    vector<vector<int>> adj(n);
    vector<int> indeg(n);
    forn(i,0,m) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        indeg[v]++;
    }
    int ans = 0;
    forn(i,0,n) {
        if(indeg[i] == 0) {
            ans = max(ans, dfs(i, adj));
        }
    }
    cout << ans-1 << endl;
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