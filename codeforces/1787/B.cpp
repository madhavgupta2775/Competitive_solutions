#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long

const int MOD2 = 1e9+7;
const int MOD = 998244353;

void solve() {
    int n, ans = 0; cin >> n;
    map<int, int> m;
    vector<pair<int, int>> v;
    while (n % 2 == 0)
    {
        m[2]++;
        n = n/2;
    }
 
    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            m[i]++;
            n = n/i;
        }
    }
 
    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
        m[n]++;
    for(auto x: m){
        v.emplace_back(x.second, x.first);
    }
    sort(v.begin(), v.end());
    for(int i = v.size()-1; i >0; i--){
        ans += (v[i].first- v[i-1].first)*v[i].second;
        v[i-1].second *= v[i].second;
    }
    ans += v[0].first*v[0].second;
    cout << ans << endl;
}   
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        solve(); 
    }
    //solve();
    return 0;
}