#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    string s, t; cin >> s >> t;
    vector<int> freq(26, 0);
    for(int i = 0; i < n; i++) {
        freq[s[i] - 'a']++;
        freq[s[i] - 'a'] %= 2;
        freq[t[i] - 'a']++;
        freq[t[i] - 'a'] %= 2;
    }
    if(freq != vector<int>(26, 0)) {
        cout << "No" << endl;
        return;
    }
    vector<pair<int, int>> ans;
    cout << "Yes" << endl;
    for(int i = 0; i < n; i++) {
        if(s[i] == t[i]) continue;
        int j = i + 1;
        while(j < n && s[j] != s[i]) j++;
        if(j < n) {
            swap(s[j], t[i]);
            ans.push_back({j, i});
            continue;
        }
        j = i + 1;
        while(j < n && t[j] != s[i]) j++;
        swap(s[j], t[j]);
        ans.push_back({j, j});
        swap(s[j], t[i]);
        ans.push_back({j, i});
    }
    cout << ans.size() << endl;
    for(auto x: ans) {
        cout << x.first + 1 << " " << x.second + 1 << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    // cout << setprecision(30);
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        solve();
    }
    return 0;
}