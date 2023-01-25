#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long
 
const int MOD2 = 1e9+7;
const int MOD = 998244353;

void solve() {
    int n, a = 0, b = 1, c = 2; cin >> n;
    bool t = true;
    vector<int> v(n);
    forn(i, 0, n){
        cin >> v[i];
        if(i>2){
            if((v[a] + v[b] + v[c])%2==0){
                if(v[a]%2 != v[i]%2){
                    a = i;
                }
                else if(v[b]%2!= v[i]%2){
                    b = i;
                }
                else if(v[c]%2 != v[i]%2){
                    c = i;
                }
            }
        }
    }
    if((v[a] + v[b] + v[c])%2 == 0){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
        cout << a+1 << " " << b+1 << " " << c+1 << endl;
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