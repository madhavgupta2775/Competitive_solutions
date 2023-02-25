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
    int n, m, temp = 0, sum = 0, p = 0, a = 0; cin >> n >> m;
    vector<int> v(n), start(n), val(n+m+1);
    forn(i, 0, n){
        cin >> v[i];
    }
    forn(i, 0, m){
        cin >> p >> a;
        val[v[p-1]-1] += i-start[p-1]+1;
        start[p-1] = i+1; v[p-1] = a;
    }
    forn(i, 0, n){
        val[v[i]-1] += m+1-start[i];
    }
    forn(i, 0, n+m+1){
        if(val[i] != 0){
            temp = m- val[i]+1;
            sum += ((m*(m+1))/2) - ((temp*(temp-1))/2);
        }
    }
    cout << sum << endl;
}   
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        solve(); 
    }
    //solve();
    return 0;
}