#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long

const int MAXN = 200100;
const int MOD = 1000000007;

void solve() {
    int n, a = 0, b = 0, j = 0; cin >> n;
    vector<int> v(n), e(n); bool c = false;
    forn(i, 0, n){
        cin >> v[i];
        e[i] = v[i];
    }
    sort(e.begin(), e.end());
    forn(i, 0, n){
        if(v[i] != e[n-1] || c){
            cout << v[i] - e[n-1] << " ";
        }
        else{
            cout << v[i] - e[n-2] << " ";
            c = true;
        }
    }
    cout << endl;
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