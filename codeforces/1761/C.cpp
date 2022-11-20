#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long

const int MAXN = 200100;
const int MOD = 1000000007;

void solve() {
    int n; cin >> n;
    vector<vector<int>> v;
    vector<pair<int, int>> a;
    string s;
    forn(i, 0, n){
        cin >> s;
        for(int j = 0; j < n; j++){
            if(s[j] == '1'){
                a.emplace_back(i, j);
            }
        }
    }
    forn(i, 0, n){
        vector<int> b;
        b.push_back(i+1);
        v.push_back(b);
    }
    forn(i, 0, a.size()){
        for(int j = 0; j < v[a[i].first].size(); j++){
            if(find(v[a[i].second].begin(), v[a[i].second].end(), v[a[i].first][j]) == v[a[i].second].end()){
                v[a[i].second].push_back(v[a[i].first][j]);
            }
        }
    }
    forn(i, 0, n){
        cout << v[i].size() << " ";
        for(int j = 0; j < v[i].size(); j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        solve(); 
    }
    return 0;
}   