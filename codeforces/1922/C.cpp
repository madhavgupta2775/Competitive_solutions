#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

const int mod = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<int> a(n); forn(i,0,n) cin >> a[i];
    int m; cin >> m;
    vector<int> f_k(n), n_k(n);
    forn(i, 0, n) {
        if(i == 0) {
            f_k[i] = 0;
        }
        else if(i == 1) {
            f_k[i] = 1;
        }
        else {
            f_k[i] = f_k[i-1];
            if((a[i-1] - a[i-2]) > (a[i] - a[i-1])) {
                f_k[i]++;
            }
            else {
                f_k[i] += a[i] - a[i-1];
            }
        }
    }
    for(int j = n-1; j >= 0; j--) {
        if(j == n-1) {
            n_k[j] = 0;
        }
        else if(j == n-2) {
            n_k[j] = 1;
        }
        else {
            n_k[j] = n_k[j+1];
            if((a[j+1] - a[j]) < (a[j+2] - a[j+1])) {
                n_k[j]++;
            }
            else {
                n_k[j] += a[j+1] - a[j];
            }
        }
    }
    forn(i, 0, m) {
        int x, y; cin >> x >> y;
        if(x < y) {
            cout << f_k[y-1] - f_k[x-1] << endl;
        }
        else {
            cout << n_k[y-1] - n_k[x-1] << endl;
        }
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