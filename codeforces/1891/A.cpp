#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

bool is_powerof_two(int n) {
    return (n && !(n & (n - 1)));
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    forn(i, 0, n) {
        cin >> a[i];
    }
    forn(i, 0, n-1) {
        if(a[i] > a[i+1] && !is_powerof_two(i+1)) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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