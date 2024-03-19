#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long
#define ull unsigned long long

const int MOD = 998244353;

void solve() {
    int m, n; cin >> n >> m;
    vector<int> a(n), b(n);
    forn(i, 0, n) cin >> a[i];
    forn(i, 0, n) cin >> b[i];
    int coins = 0;
    for(int i = n-1; i >= m; i--) {
        if(a[i] < b[i]) {
            coins += a[i];
        }
        else {
            coins += b[i];
        }
    }
    // find minimum combination of a[i] and b[i] in the range [0, m-1]
    vector<int> choices;
    int temp = 0;
    for(int i = m-1; i >= 0; i--) {
        choices.push_back(a[i] + temp);
        temp += b[i];
    }
    sort(choices.begin(), choices.end());
    cout << coins + choices[0] << endl;
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