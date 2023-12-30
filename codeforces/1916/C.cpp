#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    int odd_count = 0;
    forn(i, 0, n) {
        cin >> v[i];
    }
    int odd=0, even=0, sum = 0;
    forn(i, 0, n) {
        sum += v[i];
        if(v[i] % 2 == 0) {
            even++;
        }
        else {
            odd++;
        }
        int ans = sum - odd/3;
        if(odd % 3 == 1 && i != 0) ans--;
        cout << ans << " ";
    }
    cout << endl;
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