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
    vector<set<int>> v(n);
    vector<int> visited(n);
    queue<int> q;
    forn(i, 0, n){
        cin >> curr;
        v[i].insert(curr-1);
        v[curr-1].insert(i);
    }
    forn(i, 0, n){
        if(!visited[i]){
            visited[i] = true;
            maxsize++;
            q.push(i);
            while(!q.empty()){
                curr = q.front(); q.pop();
                if(v[curr].size() == 1){
                    sizetwo++;
                }
                for(auto x: v[curr]){
                    if(!visited[x]){
                        q.push(x);
                        visited[x] = true;
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