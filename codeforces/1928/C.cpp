#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

const int MOD = 998244353;

void solve() {
    int n, x; cin >> n >> x;
    n -= x;
    int ans = 0;
    vector<int> divisors;
    map<int, int> mp;
    for(int i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            divisors.push_back(i);
            if(i * i != n) {
                divisors.push_back(n / i);
            }
        }
    }
    for(auto d : divisors) {
        if(d %2) continue;
        int temp = d/2 + 1;
        if(temp >= x && !mp[temp]) {
            ans++;
            mp[temp] = 1;
        }
    }
    n += x; n += x-2;
    divisors.clear();
    for(int i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            divisors.push_back(i);
            if(i * i != n) {
                divisors.push_back(n / i);
            }
        }
    }
    for(auto d : divisors) {
        if(d %2) continue;
        int temp = d/2 + 1;
        if(temp >= x && !mp[temp]) {
            ans++;
            mp[temp] = 1;
        }
    }
    cout << ans << endl;
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
