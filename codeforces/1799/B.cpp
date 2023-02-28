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
    int n, sum = 0, mie = INT_MAX, ind = -1; cin >> n;
    double temp = 0;
    vector<int> v(n);
    vector<pair<int, int>> pai;
    bool one = false;
    forn(i, 0, n){
        cin >> v[i];
        if(v[i] == 1){
            one = true;
        }
        if(v[i] < mie){
            mie = v[i]; ind = i;
        }
    }
    if(one){
        forn(i, 0, n){
            if(v[i] != 1){
                cout << -1 << endl; return;
            }
        }
        cout << 0 << endl; return;
    }
    forn(i, 0, n){
        while(v[i] != mie){
            temp = v[i]; temp/= mie;
            v[i] = ceil(temp);
            pai.emplace_back(i+1, ind+1);
            if(v[i] < mie){
                mie = v[i]; ind = i; i = 0;
            }   
        }
    }
    cout << pai.size() << endl;
    forn(i, 0, pai.size()){
        cout << pai[i].first << " " << pai[i].second << endl;
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