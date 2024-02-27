#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long
#define ull unsigned long long

const int MOD = 998244353;

void solve() {
    int n; cin >> n;
    int sum = 0;
    int index_1 = -1, index_2 = -1;
    vector<int> a(n);
    forn(i, 0, n) {
        cin >> a[i];
        sum += a[i];
        if(a[i] % 3 == 2) {
            index_2 = i;
        }
        else if(a[i] % 3 == 1) {
            index_1 = i;
        }
    }
    if(sum % 3 == 0) {
        cout << 0 << endl;
        return;
    }
    else if( sum % 3 == 2 || (sum % 3 == 1 && index_1 != -1) || (sum % 3 == 2 && index_2 != -1)) {
        cout << 1 << endl;
        return;
    }
    else if(sum % 3 == 1) {
        cout << 2 << endl;
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