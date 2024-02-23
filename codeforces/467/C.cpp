#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long
#define ull unsigned long long

const int MOD = 1e9 + 7;

class ReaderWriter 
{
private: 
    mutex m;
    condition_variable cv;
    atomic <int> count;
public: 
    void write() {
        unique_lock ul(m);
        while(count > 0) {
            cv.wait(ul);
        }
        count = -1;
        //write
        count = 0; ul.unlock(); cv.notify_all();
    }
    void read() {
        unique_lock ul(m);
        while(count < 0) {
            cv.wait(ul);
        }
        count++;
        ul.unlock();
        //read
        count--;
        cv.notify_one();
    }
};

int compute(int k, int n, int m, vector<int> &sums, vector<vector<int>> &dp) {
    if(k == 0) return 0;
    if(n == 0) return -1e18;
    if(dp[k][n] != -1) return dp[k][n];
    int ans = compute(k, n-1, m, sums, dp);
    if(n >= m) {
        ans = max(ans, compute(k-1, n-m, m, sums, dp) + sums[n-m]);
    }
    return dp[k][n] = ans;
}


void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n), sums;
    int cum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        cum += a[i];
        if(i >= m-1) {
            sums.push_back(cum);
            cum -= a[i-m+1];
        }
    }
    vector<vector<int>> dp(k+1, vector<int> (n+1, -1));
    cout << compute(k, n, m, sums, dp) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(30);
    int T = 1;
    // cin >> T;
    for(int I = 1; I <= T; I++) {
        solve();
    }
    return 0;
}