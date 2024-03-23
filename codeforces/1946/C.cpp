#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long
#define ull unsigned long long

const int MOD = 1e9 + 7;

int flag = 0;
 
int DFS(vector<vector<int>> &adj, int k, int i, int x)
{
 
    int ans = 1;
 
    for (auto& it : adj[i]) 
    {
        if (it != k) 
        {
            ans += DFS(adj, i, it, x);
        }
    }
 
    if (ans >= x) 
    {
        flag++;
        ans = 0;
    }
    return ans;
}
 
void addEdge(vector<vector<int>>& adj, int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void solve() 
{
    int n, k; cin >> n >> k;
    vector<vector<int>> adj(n);
    forn(i, 0, n - 1) 
    {
        int u, v; cin >> u >> v;
        u--; v--;
        addEdge(adj, u, v);
    }
    int l = 1, r = n+1;
    while(l < r-1) 
    {
        int m = (l + r) / 2;
        flag = 0;
        DFS(adj, -1, 0, m);
        if(flag > k) 
        {
            l = m;
        } 
        else 
        {
            r = m;
        }
    }
    cout << l << endl;
}

int32_t main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(30);
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        solve();
    }
    return 0;
}