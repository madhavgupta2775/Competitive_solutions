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
    forn(i, 0, n) {
        string s; cin >> s;
        for(int j = 0; j < n; j++) {
            if(s[j] == '1') {
                a[i]++;
            }
        }
    }
    int ans = 0;
    forn(i, 0, n) {
        if(a[i] == 1) {
            cout << "TRIANGLE" << endl;
            break;
        }
        else if(a[i] > 0 && a[i+1] == a[i]) {
            cout << "SQUARE" << endl;
            break;
        }
        else if(a[i] > 0) {
            cout << "TRIANGLE" << endl;
            break;
        }
    }
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