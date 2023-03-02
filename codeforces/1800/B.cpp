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
    int n, k, burls = 0; cin >> n >> k;
    string s; cin >> s;
    vector<int> v(52);
    forn(i, 0, n){
        if(s[i] - 90 > 0){
            if(v[s[i] - 97] > 0){
                burls++; v[s[i] - 97]--;
            }
            else{
                v[s[i] - 71]++;
            }
        }
        else{
            if(v[s[i] - 39] > 0){
                burls++; v[s[i] - 39]--;
            }
            else{
                v[s[i] - 65]++;
            }
        }
    }
    forn(i, 0, 52){
        if(k == 0){
            break;
        }
        if(v[i] > 1){
            burls += min(k, v[i]/2);
            k -= min(k, v[i]/2);
        }
    }
    cout << burls << endl;
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