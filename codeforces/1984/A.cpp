#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    forn(i, 0, n) cin >> a[i];
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp[a[i]]++;
    }
    int distinct = mp.size();
    if(distinct == 1) {
        cout << "NO" << endl;
        return;
    }
    else {
        cout << "YES" << endl;
        cout << "RB";
        int i = 2;
        for (; i < n; i++) {
            if(a[i] == a[i - 1]) {
                cout << "R";
            }
            else break;
        }
        for(; i < n; i++) {
            cout << "R";
        }
        cout << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
