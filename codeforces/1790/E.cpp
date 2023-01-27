#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long

const int MOD2 = 1e9+7;
const int MOD = 998244353;

void solve() {
    int n, a = 0, b = 0; cin >> n;
    if(n%2){
        cout << -1 << endl; return;
    }
    n*= 2;
    vector<int> v;
    while(n>0){
        v.push_back(n%2);
        n/=2;
    }
    if(v[1]){
        cout << -1 << endl; return;
    }
    for(int j = v.size()-1; j >1; j--){
        if(v[j] == 1 && v[j-1] == 1){
            cout << -1 << endl; return;
        }
        else if(v[j] == 1 && v[j-1] == 0){
            a += pow(2, j-1) + pow(2, j-2);
            b += pow(2, j-2);
        }
    }
    cout << a << " " << b << endl;
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