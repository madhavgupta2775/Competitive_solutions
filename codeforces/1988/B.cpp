#include <bits/stdc++.h>
using namespace std;

#define endl "\n" 
#define int long long

const int MOD = 998244353;

void solve() {
    int n; cin >> n; 
    string s; cin >> s;
    int ones = 0, zeros = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            ones++;
            continue;
        }
        else {
            zeros++;
            while(i < n && s[i] == '0') {
                i++;
            }
            i--;
        }
    }
    if (ones > zeros) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    
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