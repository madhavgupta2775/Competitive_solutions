#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long
#define ull unsigned long long

const int MOD = 998244353;


void solve() {
    int n; cin >> n;
    vector<int> a(n);
    int lp = 1, rp = n; bool flag = true;
    forn(i, 0, n) {
        if(flag) {
            a[i] = lp;
            lp++;
        } else {
            a[i] = rp;
            rp--;
        }
        flag = !flag;
    }
    forn(i, 0, n) cout << a[i] << " ";
    cout << endl;
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
