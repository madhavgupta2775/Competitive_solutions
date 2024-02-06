#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    int a = 0, b = 0, turn = 0;
    while(n) {
        if(turn % 2) {
            a += (n % 10) * pow(10, turn/2);
        }
        else {
            b += (n % 10) * pow(10, turn/2);
        }
        n /= 10; turn++;
    }
    cout << (a+1) * (b+1) - 2 << endl;
}


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    // cout << setprecision(30);
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        solve();
    }
    return 0;
}
