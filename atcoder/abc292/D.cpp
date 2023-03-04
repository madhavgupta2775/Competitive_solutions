#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long
#define ff first
#define ss second

const int MOD2 = 1e9+7;
const int MOD = 998244353;
int sume = 0, sumv = 0; map<int, int> occ;
class Graph {
    int V; // No. of vertices
 
    // Pointer to an array containing adjacency lists
    list<int>* adj;
 
    // A function used by DFS
    void DFSUtil(int v, bool visited[]);
 
public:
    Graph(int V); // Constructor
    ~Graph();
    void addEdge(int v, int w);
    void connectedComponents();
};
 
// Method to print connected components in an
// undirected graph
void Graph::connectedComponents()
{  
    int tempe = 0, tempv = 0;
    // Mark all the vertices as not visited
    bool* visited = new bool[V];
    for (int v = 1; v < V; v++)
        visited[v] = false;
 
    for (int v = 1; v < V; v++) {
        if (visited[v] == false) {
            // print all reachable vertices
            // from v
            DFSUtil(v, visited);
            if(sume != sumv){
                cout << "No" << endl; return;
            }
            sume = 0; sumv = 0;
        }
    }
    delete[] visited;
    cout << "Yes" << endl; return;
}
 
void Graph::DFSUtil(int v, bool visited[])
{
    // Mark the current node as visited and print it
    visited[v] = true; sumv++;
    sume += occ[v];
 
    // Recur for all the vertices
    // adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
Graph::~Graph() { delete[] adj; }
 
// method to add an undirected edge
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void solve() {
    int n, m; cin >> n >> m;
    Graph g(n+1);
    vector<int> v(2);
    forn(i, 0, m){
        cin >> v[0] >> v[1];
        g.addEdge(v[0], v[1]);
        occ[v[0]]++;
    }
    g.connectedComponents();
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