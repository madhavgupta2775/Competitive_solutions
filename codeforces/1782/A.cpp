#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long
 
const int MOD2 = 1e+7;
const int MOD = 998244353;
 
void solve() {
    int w, d, h, ans = 0; cin >> w >> d >> h;
    int a, b, f, g; cin >> a >> b >> f >> g;
    int df1 = a, df2 = w-a, df3 = b, df4 = d - b;
    int dc1 = f, dc2 = w-f, dc3 = g, dc4 = d - g;
    ans = h + abs(a - f) + abs(b - g) + 2*(min(min(min(df1, df2), min(df3, df4)), min(min(dc1, dc2), min(dc3, dc4))));
    cout << ans << endl;
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