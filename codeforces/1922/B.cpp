#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

const int mod = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<int> a(n), freq(n+1), cf(n+1); forn(i,0,n) {
        cin >> a[i];
        freq[a[i]]++;
    }
    int prev = 0;
    forn(i, 0, n+1) {
        cf[i] = prev + freq[i];
        prev = cf[i];
    }
    vector<bool> vis(n+1);
    int ans = 0;
    forn(i, 0, n) {
        int x = freq[a[i]];
        if(a[i] > 0 && !vis[a[i]]) {
            vis[a[i]] = true;
            int y = cf[a[i]-1];
            ans += ((x*(x-1)*(x-2))/6);
            ans += ((x*(x-1)*y)/2);
        }
        else if(a[i] == 0 && !vis[a[i]]){
            vis[a[i]] = true;
            ans += ((x*(x-1)*(x-2))/6);
        }
    }
    cout << ans << endl;
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