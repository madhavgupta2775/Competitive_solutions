#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long
#define ull unsigned long long

const int MOD = 998244353;

void solve() {
    int n; cin >>n;
    vector<int> a(n);
    int ones = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] == 1) ones++;
    }
    if(ones > 1) {
        cout << "NO" << endl;
    }
    else if(ones == 1) {
        cout << "YES" << endl;
    }
    else {
        sort(a.begin(), a.end());
        int count = 1;
        forn(i, 1, n) {
            if(a[i] == a[0]) {
                count++;
            }
        }
        if(count == 1) {
            cout << "YES" << endl;
            return;
        }
        forn(i, 1, n) {
            if(a[i] % a[0] != 0) {
                cout << "YES" << endl;
                return;
            }
        }
        cout << "NO" << endl;
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