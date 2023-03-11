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
    int n, m, s, l, ind = 1; cin >> n >> m >> s >> l;
    vector<int> v(n+1);
    forn(i, 1, n+1){
        v[i] = i;
    }
    if(n*s <= m && n*min(n, l) >= m){
        forn(i, 0, s){
            for(int j = 1; j < n+1; j++){
                cout << j << " " << v[j] << endl;
                if(v[j] < n){
                    v[j]++;
                }
                else{
                    v[j] = 1;
                }
                m--;
            }
        }
        while(m > 0){
            cout << ind << " " << v[ind] << endl;
            if(v[ind] < n){
                v[ind]++;
            }
            else{
                v[ind] = 1;
            }
            if(ind < n){
                ind++;
            }
            else{
                ind = 1;
            }
            m--;
        }
    }
    else{
        cout << -1 << endl;
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
    //  solve();
    return 0;
}