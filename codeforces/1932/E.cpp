#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long
#define ull unsigned long long

const int MOD = 998244353;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> a(n); 
    forn(i, 0, n) {
        a[i] = s[i] - '0';
    }
    // the array represent a number a
    // we need to find sum of a + a / 10 + a / 100 + ... + a / 10^k
    vector<int> ans(n);
    int temp = 0;
    forn(i, 0, n) {
        temp += a[i];
        ans[i] = temp;
    }
    int carry = 0;
    for(int i = n - 1; i >= 0; i--) {
        ans[i] += carry;
        carry = ans[i] / 10;
        ans[i] %= 10;
    }
    while(carry) {
        ans.insert(ans.begin(), carry % 10);
        carry /= 10;
    }
    bool flag = false;
    for(int i = 0; i < ans.size(); i++) {
        if(ans[i] == 0 && !flag) {
            continue;
        }
        else {
            flag = true;
            cout << ans[i];
        }
    }
    cout << endl;
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