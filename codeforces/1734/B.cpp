#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long

const int MAXN = 200100;
const int MOD = 1000000007;

void solve() {
    int n; cin >> n;
    forn(i, 0, n){
        cout << 1 << " ";
        for(int j = 0; j < i-1; j++){
            cout << 0 << " ";
        }
        if(i> 0){cout << 1 << " ";}
        cout << endl;
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