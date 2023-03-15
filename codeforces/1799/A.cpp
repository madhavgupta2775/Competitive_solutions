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
    int n, m, temp; cin >> n >> m;
    map<int, int> next, prev, kick;
    vector<bool> occ(n+1);
    forn(i, 1, n){
        next[i] = i+1;
        prev[i+1] = i;
    }
    next[n] = -1; prev[-1] = n;
    next[-1] = 1; prev[1] = -1;
    forn(i, 0, m){
        cin >> temp;
        if(next[temp] == 0){
            if(prev[-1] <= n && occ[prev[-1]] == false){
                kick[prev[-1]] = i+1;
                occ[prev[-1]] = true;
            }
            next[prev[-1]] = 0;
            prev[-1] = prev[prev[-1]];
            prev[next[prev[-1]]] = 0;
            next[prev[-1]] = -1;
            prev[next[-1]] = temp; prev[temp] = -1;
            next[temp] = next[-1];
            next[-1] = temp;
        }
        else{
            next[prev[temp]] = next[temp];
            prev[next[temp]] = prev[temp];
            next[temp] = next[-1]; next[-1] = temp;
            prev[temp] = -1; prev[next[temp]] = temp;
        }
    }
    forn(i, 1, n+1){
        if(kick[i] != 0){
            cout << kick[i] << " ";
        }
        else{
            cout << -1 << " ";
        }
    }
    cout << endl;

}   
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        solve(); 
    }
    // solve();
    return 0;
}