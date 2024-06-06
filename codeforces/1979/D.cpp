#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

const int MOD = 1e9 + 7;

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int first = -1, second = -1, curr = 1, f_s = 0, s_s = 0;
    // check for groups of k consecutive 1's or 0's
    for (int i = 1; i < n; i++) {
        if(s[i] != s[i - 1]) {
            if(curr != k && f_s) {
                cout << -1 << endl;
                return;
            }
            else if(!f_s && curr != k) {
                f_s = curr;
                first = i - curr;
            }
            curr = 1;
        }
        else {
            curr++;
        }
    }
    if(!f_s && curr == k) {
        cout << n << endl;
    }
    else if(!f_s && curr != k) {
        cout << -1 << endl;
    }
    else if(f_s && curr > k) {
        cout << -1 << endl;
    }
    else if((f_s != 2 * k) && s[first] != s[n - 1]) {
        cout << -1 << endl;
    }
    else if(s[first] == s[n - 1] && (f_s + curr != k && f_s + curr != 2 * k)) {
        cout << -1 << endl;
    }
    else {
        if(f_s == 2 * k) {
            cout << first + k << endl;
        }
        else {
            cout << first + k - curr << endl;
        }
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
