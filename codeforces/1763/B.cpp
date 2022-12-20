#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long
 
const int MAXN = 200100;
const int MOD = 998244353;
 
void solve() {
    int n, k, a = 0, b = 0, j = 0; cin >> n >> k;
    vector<pair<int, int>> v(n);
    forn(i, 0, n){
        cin >> v[i].second;
        a = max(a, v[i].second);
    }
    forn(i, 0, n){
        cin >> v[i].first;
    }
    sort(v.begin(), v.end());
    while(k>0 && a>0){
        b += k; a -= k;
        while(v[j].second<=b && j < n){
            j++;
        }
        k -= v[j].first;
    }
    if(a <= 0){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
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