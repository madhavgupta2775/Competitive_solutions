#include <bits/stdc++.h>
using namespace std;

#define endl "\n" 
#define int long long

const int MOD = 998244353;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> a(n, vector<int>(m));
    auto snow = a;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> a[i][j];
    }
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            snow[i][j] = s[j] - '0';
            if(snow[i][j] == 0) snow[i][j] = -1;
        }
    }
    int sum_snowy = 0, sum_not_snowy = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(snow[i][j] == 1) sum_snowy += a[i][j];
            else sum_not_snowy += a[i][j];
        }
    }
    // add any numbers c to submatrices of size k * k to make sum_snowy = sum_not_snowy
    int diff = abs(sum_snowy - sum_not_snowy);
    vector<vector<int>> prefix_j(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            prefix_j[i][j] = snow[i][j];
            if(j > 0) prefix_j[i][j] += prefix_j[i][j - 1];
        }
    }
    int netgcd = 1e18;
    for (int i = 0; i + k - 1 < n; i++) {
        for (int j = 0; j + k - 1 < m; j++) {
            int sum = 0;
            for (int x = i; x < i + k; x++) {
                sum += prefix_j[x][j + k - 1];
                if(j > 0) sum -= prefix_j[x][j - 1];
            }
            if(netgcd == 1e18 && sum != 0) netgcd = sum;
            else if(sum != 0) netgcd = __gcd(netgcd, abs(sum));
        }
    }
    if(diff % netgcd != 0) {
        cout << "NO" << endl;
        return;
    }
    else {
        cout << "YES" << endl;
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
