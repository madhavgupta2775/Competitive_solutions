#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long

const int MOD2 = 1e9+7;
const int MOD = 998244353;

void solve() {
    int n, temp = 0, i = 1, ans = 0; cin >> n;
    map<int, int> m;
    forn(i, 0, n){
        cin >> temp;
        m[temp]++;
    }
    map<int, int>::iterator tt = m.begin(); tt++;
    for(auto it : m){
        if(i == 1){
            ans += it.second;
        }
        if(i != m.size()){
            if(tt->first - it.first != 1){
                ans += tt->second;tt++;i++; continue;
            }
            ans += max(0ll, tt->second - it.second);
            tt++;
        }
        i++;
    }
    cout << ans << endl;
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