#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

const int MOD = 1e9 + 7;

char symm(string helper, char c) {
    // return the symmetric character of c in helper
    
    // find the index of c in helper
    int index = helper.find(c);
    // find the symmetric index
    int symm_index = helper.size() - index - 1;
    return helper[symm_index];
}

void solve() {
    int n; cin >> n;
    string b; cin >> b;
    set<char> s;
    for(auto c : b) {
        s.insert(c);
    }
    string helper;
    for(auto c : s) {
        helper += c;
    }
    string ans;
    for(auto c1: b) {
        ans += symm(helper, c1);
    }
    cout << ans << endl;
}


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << fixed << setprecision(30);
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        solve();
    }
    return 0;
}