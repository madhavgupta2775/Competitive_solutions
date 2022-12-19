#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long
 
const int MAXN = 200100;
const int MOD = 998244353;
 
void solve() {
    int n, a = 0, c = 0; cin >> n;
    vector<int> v(11), t;
    forn(i, 0, n){
        cin >> a;
        while(a>0){
            t.push_back(a%2);
            a/=2;
        }
        forn(i, 0, t.size()){
            if(t[i] == 1){
                v[i]++;
            }
        }
        t = {};
    }
    forn(i, 0, 11){
        if(v[i] == n){
            c += 1<<i; a += 1<<i;
        }
        else if(v[i] > 0){
            c += 1<<i;
        }
    }
    cout << c - a << endl;
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