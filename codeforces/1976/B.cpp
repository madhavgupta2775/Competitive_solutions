#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n + 1);
    forn(i, 0, n) cin >> a[i];
    forn(i, 0, n + 1) cin >> b[i];
    int ans = 0; 
    forn(i, 0, n) {
        ans += abs(a[i] - b[i]);
    }
    int last = b[n];
    bool flag = false;
    int temp = 1e18;
    forn(i, 0, n) {
        if (last >= a[i] && b[i] >= last) {
            flag = true;break;
        }
        else if(last <= a[i] && b[i] <= last) {
            flag = true; break;
        }
        else {
            temp = min(temp, abs(b[i] - last));
            temp = min(temp, abs(a[i] - last));
        }
    }
    if(!flag) {
        ans += temp;
    }
    ans++;
    cout << ans << endl;
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
