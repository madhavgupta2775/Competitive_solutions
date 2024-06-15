#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl "\n"

const int MOD = 1e9 + 7;

// int compute(int n, int k, int i, vector<int>& a) {
//    if(i == n && k == 0) return 1;
//    else if(i == n || k <= 0) return 0;
//    if(dp[i][k] != -1) return dp[i][k];
//    dp[i][k] = 0;
//    if(i == n - 1 && a[i] >= k) return dp[i][k] = 1;
//    for (int j = 0; j <= a[i]; j++) {
//       dp[i][k] += compute(n, k - j, i + 1, a);
//    }
//    dp[i][k] %= MOD;
//    // cout << "i k ";
//    // cout << i << " " << k << endl;
//    // cout << "dp[i][k]: " << dp[i][k] << endl;
//    return dp[i][k];
// }

void solve() {
   int n, k; cin >> n >> k;
   vector<int> a(n); for (int i = 0; i < n; i++) cin >> a[i];
   vector<int> dp1(k + 1), dp2(k + 1, 1);
   for (int i = 0; i < n; i++) {
      for (int j = 0; j <= k; j++) {
         dp1[j] = dp2[j];
         if(j > a[i]) dp1[j] -= dp2[j - a[i] - 1];
         if(j > 0) dp1[j] += dp1[j - 1];
         dp1[j] %= MOD;
      }
      dp2 = dp1;

   }
   int ans = dp1[k];
   if(k > 0) ans -= dp1[k - 1];
   ans = ((ans % MOD) + MOD) % MOD;
   cout << ans << endl;
}

int32_t main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int T = 1;
   // cin >> T;
   for (int I = 0; I < T; I++) {
      solve();
   }
   return 0;
}