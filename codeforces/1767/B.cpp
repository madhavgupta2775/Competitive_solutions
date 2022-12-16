#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long
 
const int MAXN = 200100;
const int MOD = 998244353;
 
void solve() {
    int n; cin >> n;
    double a = 0;
    vector<int> v(n), e;
    forn(i, 0, n){
        cin >> v[i];
        if(v[i]>v[0]){
            e.push_back(v[i]);  
        }
    }
    sort(e.begin(), e.end());
    forn(i, 0, e.size()){
        if(e[i]>v[0]){
            a = e[i]+v[0];
            a/=2;
            v[0] = ceil(a);
        }
    }
    cout << v[0] << endl;
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