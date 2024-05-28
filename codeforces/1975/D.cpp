#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<vector<int>> adj(n);
    int a, b; cin >> a >> b;
    a--; b--;
    forn(i, 0, n-1) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int root = -1;
    int ans = 0;
    // find the path from a to b using dfs
    vector<int> path;
    vector<int> vis(n, 0);
    // root will be mid point of the path
    function<void(int, int)> dfs = [&](int u, int p) {
        if(u == b) {
            root = u;
            path.push_back(u);
            return;
        }
        vis[u] = 1;
        for(auto x: adj[u]) {
            if(x != p && !vis[x]) {
                dfs(x, u);
                if(root != -1) {
                    path.push_back(u);
                    return;
                }
            }
        }
    };
    dfs(a, -1);
    root = path[path.size() / 2];
    ans = (path.size()) / 2;
    // find longest path from root
    vector<int> dis(n, -1);
    dis[root] = 0;
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto x: adj[u]) {
            if(dis[x] == -1) {
                dis[x] = dis[u] + 1;
                q.push(x);
            }
        }
    }
    ans += 2 * (n - 1);
    // find the longest path from root
    int max_dis = 0;
    for(auto x: dis) {
        max_dis = max(max_dis, x);
    }
    ans -= max_dis;
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}