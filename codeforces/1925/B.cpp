#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

const int MOD = 1e9 + 7;

void factorize(int x, vector<int> &factors) {
    for(int i = 2; i*i <= x; i++) {
        if(x % i == 0) {
            factors.push_back(i);
            factors.push_back(x/i);
        }
    }
    factors.push_back(1); factors.push_back(x);
    sort(factors.begin(), factors.end());
}

void solve() {
    int x, n; cin >> x >> n;
    if(x % n == 0) {
        cout << x/n << endl;
    }
    else {
        vector<int> factors;
        factorize(x, factors);
        int ans = 1;
        for(auto it: factors) {
            if(x/ it >= n) {
                ans = max(ans, it);
            }
        }
        cout << ans << endl;
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