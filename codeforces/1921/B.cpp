#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

const int mod = 1e9+7;

void solve() {
    int n; cin >> n;
    string a, b; cin >> a >> b;
    int ans = 0, excess_in_a = 0;
    forn(i, 0, n) {
        if(a[i] == b[i]) continue;
        if(a[i] == '1') {
            if(excess_in_a < 0) {
                ans++;
            }
            excess_in_a++;
        }
        else {
            if(excess_in_a > 0) {
                ans++;
            }
            excess_in_a--;
        }
    }
    cout << ans + abs(excess_in_a) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << setprecision(30);
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        solve();
    }
    return 0;
}