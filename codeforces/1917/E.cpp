#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

const int MOD = 1e9 + 7;

void solve() {
    int n, k; cin >> n >> k;
    if(k%2) {
        cout << "No" << endl;
        return;
    }
    bool flag = false;
    if(k*2 > n*n) {
        k = n*n - k;
        flag = true;
    }
    if(k == 2) {
        if(n == 2) {
            cout << "Yes" << endl;
            cout << "1 0" << endl;
            cout << "0 1" << endl;
        }
        else {
            cout << "No" << endl;
        }
        return;
    }
    cout << "Yes" << endl;
    vector<vector<int>> ans(n, vector<int>(n, 0));
    bool flag2 = false;
    if(k % 4) {
        ans[0][0] = ans[0][1] = ans[1][0] = ans[1][2] = ans[2][1] = ans[2][2] = 1;
        k -= 6; flag2 = true;
    }
    if(k > 0 && flag2) {
        for(int i = 4; i < n; i += 2) {
            for(int j = 0; j < n; j += 2) {
                if(k > 0) {
                    ans[i][j] = ans[i+1][j] = ans[i][j+1] = ans[i+1][j+1] = 1;
                    k -= 4;
                }
            }
        }
        for(int i = 0; i < 4; i += 2) {
            for(int j = 4; j < n; j += 2) {
                if(k > 0) {
                    ans[i][j] = ans[i+1][j] = ans[i][j+1] = ans[i+1][j+1] = 1;
                    k -= 4;
                }
            }
        }
    }
    else if(k > 0) {
        for(int i = 0; i < n; i += 2) {
            for(int j = 0; j < n; j += 2) {
                if(k > 0) {
                    ans[i][j] = ans[i+1][j] = ans[i][j+1] = ans[i+1][j+1] = 1;
                    k -= 4;
                }
            }
        }
    }
    if(flag) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                ans[i][j] ^= 1;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
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