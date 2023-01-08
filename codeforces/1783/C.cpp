#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long
 
const int MAXN = 200100;
const int MOD = 1e9+7;
 
void solve() {
    int n, m, a = 0, b = 0; cin >> n >> m;
    vector<pair<int, int>> v;
    vector<int> u(n);
    forn(i, 0, n){
        cin >> u[i];
        v.emplace_back(u[i], i);
    }
    sort(v.begin(), v.end());
    forn(i, 0, n){
        if(m >= v[i].first){
            m -= v[i].first;
            b++;
        }
        else{
            break;
        }
    }
    if(b==0){
        cout << n+1 << endl; return;
    }
    if(b==n){
        cout << 1 << endl; return;
    }
    if(m >= u[b]-v[b-1].first){
        cout << n-b << endl;
    }
    else{
        cout << n-b+1 << endl;
    }
}
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        solve(); 
    }
    return 0;
}