#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long
#define ull unsigned long long

const int MOD = 998244353;

void solve() {
    int n, k; cin >> n >> k;
    int t1 = (n/2) + (n%2), step = 0;
    // 1 3 5 7 ... 2 6 10 14 ... 4 12 20 28 ... 8 24 40 56 ...
    while(k > 0) {
        if(k <= t1) {
            int temp = (k-1)*(1ll<<(step+1)); 
            temp += (1ll<<step);
            cout << temp << endl;
            return;
        }
        k -= t1;
        int t2 = (t1/2) + (t1%2);
        int temp = (t2-1)*(1ll<<(step+2)); temp += (1ll<<(step+1));
        if(temp <= n) {
            t1 = t1/2 + (t1%2);
        }
        else {
            t1 = t1/2;
        }
        step++;
    }
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