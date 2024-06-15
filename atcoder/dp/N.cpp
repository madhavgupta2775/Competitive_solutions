#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl "\n"

const int MOD = 1e9 + 7;

int dp[401][401];
int pre[401];

int que(int i, int j) {
   return (i == 0) ? pre[j] : pre[j] - pre[i - 1];
}

int compute(vector<int>& a, int i, int j) {
   if(i == j) return 0;
   if(dp[i][j] != -1) return dp[i][j];
   dp[i][j] = 1e18;
   for (int k = i; k < j; k++) {
      dp[i][j] = min(dp[i][j], compute(a, i, k) + compute(a, k + 1, j));
   }
   dp[i][j] += que(i, j);
   // cout << "i j: " << i << " " << j << " dp[i][j]: " << dp[i][j] << endl;
   return dp[i][j];
}

void solve() {
   memset(dp, -1, sizeof(dp));
   int n; cin >> n;
   vector<int> a(n); for (int i = 0; i < n; i++) cin >> a[i];
   pre[0] = a[0];
   for (int i = 1; i < n; i++) pre[i] = pre[i - 1] + a[i];
   cout << compute(a, 0, n - 1) << endl;
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