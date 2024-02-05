#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<int> a(n), indices(n); 
    vector<pair<int, int>> ans;
    forn(i, 0, n) {
        cin >> a[i];
        indices[a[i]-1] = i;
    }
    forn(i, 0, n) {
        if(a[i] != i+1) {
            int x = indices[i]; bool flag = false;
            if(abs(x - i) >= n/2) {
                ans.push_back({i+1, x+1});
                swap(a[i], a[x]);
                swap(indices[a[i]-1], indices[a[x]-1]);
                continue;
            }
            if((i < n/2 && x >= n/2) || (i >= n/2 && x < n/2)) 
                flag = true;
            if(i < n/2) {
                ans.push_back({i+1, n});
                swap(a[i], a[n-1]);
            }
            else {
                ans.push_back({i+1, 1});
                swap(a[i], a[0]);
            }
            if(x < n/2) {
                ans.push_back({n, x+1});
                swap(a[n-1], a[x]);
            }
            else {
                ans.push_back({1, x+1});
                swap(a[0], a[x]);
            }
            if(flag) {
                ans.push_back({n, 1});
                swap(a[n-1], a[0]);
            }
            if(i < n/2) {
                ans.push_back({i+1, n});
                swap(a[i], a[n-1]);
            }
            else {
                ans.push_back({i+1, 1});
                swap(a[i], a[0]);
            }
            if(flag) {
                if(x < n/2) {
                    ans.push_back({n, x+1});
                    swap(a[n-1], a[x]);
                }
                else {
                    ans.push_back({1, x+1});
                    swap(a[0], a[x]);
                }
            }
            swap(indices[a[i]-1], indices[a[x]-1]);
        }
    }
    cout << ans.size() << endl;
    for(auto x: ans) {
        cout << x.first << " " << x.second << endl;
    }

    // debug
    // for(auto x: a) cout << x << " ";
    // cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    // cout << setprecision(30);
    int T = 1;
    // cin >> T;
    for(int I = 1; I <= T; I++) {
        solve();
    }
    return 0;
}