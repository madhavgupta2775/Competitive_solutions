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
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            int ones = 0;int temp = 0, temp2 = 0;
            for(int k = i; k <= j; k++) {
                if(s[k] == '1' && !temp && !temp2) {
                    ones++; temp = 1;
                }
                else {
                    temp2 = temp; temp = 0;
                }
            }
            ans += ones;
        }
    }
    cout << ans << endl;
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
