#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long
#define ff first
#define ss second
#define pb push_back
int isprime(int n) {
    if (n % 3 == 0)
        return 3;
    forn(i, 4, sqrt(n)+1) {
        if(n % i == 0)
            return i;
    }
    return -1;
}

void solve() {
    int l, r; cin >> l >> r;
    if(r < 4) {
        cout << -1 << endl;
        return;
    }
    if(r % 2 == 0) {
        cout << r/2 << " " << r/2 << endl;
    }
    else if(r > l) {
        cout << (r-1)/2 << " " << (r-1)/2 << endl;
    }
    else {
        int s = isprime(r);
        if(s == -1) {
            cout << -1 << endl;
            return;
        }
        int ans = r/s;
        cout << ans << " " << r-ans << endl;
    }
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