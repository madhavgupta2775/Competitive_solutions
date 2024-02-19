#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long
#define ull unsigned long long

const int MOD = 998244353;

vector<int> ans;

int find_sum(int n) {
    int sum = 0;
    while(n) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

void solve() {
    int n;
    cin >> n;
    cout << ans[n] << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(30);
    int T = 1;
    cin >> T;
    ans.push_back(0);
    forn(i, 1, 2 * 1e5 + 5) {
        ans.push_back(ans[i - 1] + find_sum(i));
    }
    for(int I = 1; I <= T; I++) {
        solve();
    }
    return 0;
}