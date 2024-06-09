#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

const int MOD = 998244353;

void solve() {
    int n; cin >> n;
    vector<int> a(n); forn(i, 0, n) cin >> a[i];
    int max_num = 0, min_num = 0;
    int max_count = 1, min_count = 1;
    for (int i = 0; i < n; i++) {
        if(a[i] >= 0) {
            int temp = 0;
            if(max_num + a[i] >= abs(min_num + a[i])) {
                temp += (max(max_count, 1ll) * 2) % MOD;
            }
            if(max_num != min_num && max_num + a[i] <= abs(min_num + a[i])) {
                if(min_num + a[i] >= 0) temp += (min_count * 2) % MOD;
                else temp += min_count;
            }
            max_num = max(max_num + a[i], abs(min_num + a[i]));
            if(min_num + a[i] >= 0) min_count = (min_count * 2) % MOD;
            max_count = temp;
            min_num += a[i];
            min_count %= MOD;
            max_count %= MOD;
        }
        else {
            int temp = 0;
            if(abs(max_num + a[i]) >= abs(min_num + a[i])) {
                if(max_num + a[i] >= 0) temp = (max_count * 2) % MOD;
                else temp = max_count;
            }
            if(max_num != min_num && abs(max_num + a[i]) <= abs(min_num + a[i])) {
                if(min_num + a[i] >= 0) temp += (min_count * 2) % MOD;
                else temp += min_count;
            }
            max_num = max(abs(max_num + a[i]), abs(min_num + a[i]));
            if(min_num + a[i] >= 0) min_count = (min_count * 2) % MOD; 
            min_num += a[i]; min_count %= MOD;
            max_count = temp; max_count %= MOD;
        }
    }  
    cout << max_count << endl;
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
