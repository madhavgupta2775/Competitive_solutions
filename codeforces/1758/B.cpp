#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long

const int MAXN = 200100;
const int MOD = 1000000007;

void solve() {
    int n; cin >> n;
    if(n % 2 == 1){
        forn(i, 0, n){
            cout << 7 << " ";
        }
        cout << endl; return;
    }
    else{
        cout << 5 << " " << 15 << " ";
        forn(i, 2, n){
            cout << 10 << " ";
        }
        cout << endl; return;
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