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
    int n, x, y;
    cin >> n >> x >> y;
    int ans = 0;
    int g = lcm(x, y);
    g = n/g;
    x = n/x - g;
    y = n/y - g;
    if(x != 0) ans += (n * (n + 1))/2 - ((n- x) * (n - x + 1))/2;
    if(y != 0) ans -= ((y) * (y + 1))/2;
    cout << ans << endl;
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