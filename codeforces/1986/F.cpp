#include <bits/stdc++.h>
using namespace std;

#define endl "\n" 
#define int long long

const int MOD = 998244353;

void IS_BRIDGE(int v,int to); // some function to process the found bridge
int n; // number of nodes
vector<vector<int>> adj; // adjacency list of graph

vector<bool> visited;
vector<int> tin, low, comp_s;
int timer;
int ans;

void dfs(int v, int p = -1) {
    visited[v] = true;
    comp_s[v] = 1;
    tin[v] = low[v] = timer++;
    bool parent_skipped = false;
    for (int to : adj[v]) {
        if (to == p && !parent_skipped) {
            parent_skipped = true;
            continue;
        }
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            comp_s[v] += comp_s[to];
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                IS_BRIDGE(v, to);
        }
    }
}

void find_bridges() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    comp_s.assign(n, 0);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}

void IS_BRIDGE(int v, int to) {
    int x = n - comp_s[to];
    int a = (x * (x - 1)) / 2;
    int b = (comp_s[to] * (comp_s[to] - 1)) / 2;
    ans = min(ans, a + b);
}

void solve() {
    int m; 
    cin >> n >> m;
    adj.assign(n, vector<int>());
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    comp_s.assign(n, 0);

    for (int i = 0; i < m; i++) {
        int u, v; 
        cin >> u >> v; 
        u--; v--;
        adj[u].push_back(v); 
        adj[v].push_back(u);
    }
    ans = (n * (n - 1)) / 2;
    find_bridges();
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
