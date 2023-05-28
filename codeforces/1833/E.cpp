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
    int n, maxsize = 0, sizetwo = 0, curr = 0, minsize = 0; cin >> n;
    vector<vector<int>> v(n);
    map<pair<int, int>, bool> visited, pushed;
    queue<int> q;
    forn(i, 0, n){
        cin >> curr;
        if(!pushed[{i, curr-1}])
            v[i].push_back(curr-1); pushed[{i, curr-1}] = true;
        if(!pushed[{curr-1, i}])
            v[curr-1].push_back(i); pushed[{curr-1, i}] = true;
    }
    forn(i, 0, n){
        if(!visited[{i, v[i][0]}]){
            maxsize++;
            q.push(i);
            while(!q.empty()){
                curr = q.front(); q.pop();
                if(v[curr].size() == 1){
                    sizetwo++;
                }
                for(int j = 0; j < v[curr].size(); j++){
                    if(!visited[{curr, v[curr][j]}]){
                        q.push(v[curr][j]);
                        visited[{curr, v[curr][j]}] = true;
                        visited[{v[curr][j], curr}] = true;
                    }
                }
            }
        }
    }
    minsize = maxsize - max(sizetwo/2 - 1, 0ll);
    cout << minsize << " " << maxsize << endl;
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