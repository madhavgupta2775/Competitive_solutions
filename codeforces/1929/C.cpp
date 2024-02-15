#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long
#define ull unsigned long long

const int MOD = 998244353;


void solve() {
    int k, x, a; cin >> k >> x >> a;
    int bet = 1, coins = a;
    forn(i, 0, x) {
        if(coins <= 0) {
            cout << "NO" << endl;
            return;
        }
        bet = ((a - coins) / (k-1))+ 1;
        coins -= bet;
    }
    if(coins * k > a) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(30);
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        solve();
    }
    return 0;
}
