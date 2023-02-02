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
    int n, temp = 0, i = 1, ans = 0; cin >> n;
    multiset<int> m;
    forn(i, 0, n){
        cin >> temp;
        m.insert(temp);
    }
    multiset<int>::iterator tt = m.begin();
    for(auto it : m){
        if(i == 1){
            ans += m.count(it);
            i++; continue;
        }
        else if(it-*tt ==1){
            ans += max(0ll, (int)m.count(it) - (int)m.count(*tt));
        }
        else if(it-*tt >1){
            ans += m.count(it);
        }
        i++; tt++;
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