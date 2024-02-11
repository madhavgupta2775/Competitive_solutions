#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

const int MOD = 998244353;

int compute(vector<int> &c, int k, int n, int b, int x) {
    int ans = 0;
    forn(i, 0, n) {
        int temp = (c[i] * (c[i] - 1)) / 2;
        int rem = c[i] % k;
        int div = c[i] / k;
        temp -= rem* (((div + 1) * div) / 2) + (k - rem) * ((div * (div - 1)) / 2);
        ans += temp * b;
    }
    return ans - x * (k - 1);
}

void solve() {
    int n, b, x; cin >> n >> b >> x;
    vector<int> c(n);
    int ans = 0, max_val = 0;
    forn(i, 0, n) {
        cin >> c[i];
    }
    sort(c.begin(), c.end());
    int l = 1, r = c[n-1];
    while(l <= r) {
        int mid = (l + r) / 2;
        int templ = compute(c, max(1ll, mid-1), n, b, x), tempr = compute(c, mid+1, n, b, x), tempmid = compute(c, mid, n, b, x);
        if(tempmid >= max(templ, tempr)) {
            ans = max(ans, tempmid);
            break;
        } 
        else if(tempmid < tempr) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    cout << max(ans, 0ll) << endl;
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
