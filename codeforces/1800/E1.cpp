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
    int n, k; cin >> n >> k;
    string s, curse; cin >> s >> curse;
    vector<int> v(26), a(26);
    forn(i, 0, n){
        a[s[i]- 'a']++;
        a[curse[i] - 'a']--;
    }
    if(a != v){
        cout << "NO" << endl;
    }
    else{
        if(s.size() < 2*k){
            forn(i, max(0ll, n-k), min(n, k)){
                if(s[i] != curse[i]){
                    cout << "NO" << endl; return;
                }
            }
        }
        cout << "YES" << endl;
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
    // solve();
    return 0;
}