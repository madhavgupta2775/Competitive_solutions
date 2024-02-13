#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long
#define ull unsigned long long

const int MOD = 998244353;

int count_ending_zeros(int x) {
    int cnt = 0;
    while(x % 10 == 0) {
        cnt++;
        x /= 10;
    }
    return cnt;
}

int count_digits(int x) {
    int cnt = 0;
    while(x > 0) {
        cnt++;
        x /= 10;
    }
    return cnt;
}

void solve() {
    int n, k; cin >> n >> k;
    vector<vector<int>> ss(k, vector<int>(n));
    vector<map<int, int>> last(n);
    forn(i, 0, k) {
        for(int j = 0; j < n; j++) {
            cin >> ss[i][j];
            last[j][ss[i][j]]++;
        }
    }
    if(k == 1) {
        cout << "Yes" << endl;
        return;
    }
    if(k < 3) {
        int a = ss[0][0], b = ss[1][0];
        vector<int> order1, order2;
        for(int i = 1; i < n; i++) {
            if(ss[0][i] != b && ss[0][i] != a) {
                order1.push_back(ss[0][i]);
            }
            if(ss[1][i] != a && ss[1][i] != b) {
                order2.push_back(ss[1][i]);
            }
        }
        if(order1 == order2) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    else {
        vector<int> order(n); int ok = 0;
        int val = 0;
        for(int i = 0; i < n-1; i++) {
            if(last[i].size() == 2) {
                int temp = 0;
                for(auto x : last[i]) {
                    if(x.second == 1) temp++;
                    else if(x.second == k-1) temp++;
                    else temp--;
                }
                if(temp == 2) {
                    for(auto x : last[i]) {
                        if(x.second == k-1) val = x.first;
                    }
                    order[i-1] = val; ok = 1e9;
                    break;
                }
            }
            else if(last[i].size() == 1) {
                ok++;
            }
        }
        if(last[n-1].size() == 2 && ok < 1e9) {
            int temp = 0;
            for(auto x : last[n-1]) {
                if(x.second == 1) temp++;
                else if(x.second == k-1) temp++;
                else temp--;
            }
            if(temp == 2) {
                for(auto x : last[n-1]) {
                    if(x.second == k-1) val = x.first;
                }
                order[n-1] = val; ok = 1e9;
            }
        }
        else if(last[n-1].size() == 1 && ok < 1e9) {
            ok++;
        }
        if(ok < n) {
            cout << "No" << endl;
            return;
        }
        if(ok == n) {
            cout << "Yes" << endl;
            return;
        }
        forn(i, 0, k) {
            int cnt = 0;
            if(ss[i][0] == val) {
                for(int j = 1; j < n; j++) {
                    if(order[cnt] == val) cnt++;
                    order[cnt] = ss[i][j]; cnt++;
                }
            }
        }
        forn(i, 0, k) {
            int cnt = 0;
            if(ss[i][0] == val) continue;   
            for(int j = 1; j < n; j++) {
                if(order[cnt] == ss[i][0]) cnt++;
                if(ss[i][j] != order[cnt]) {
                    cout << "No" << endl;
                    return;
                }
                cnt++;
            }
        }
        cout << "Yes" << endl;
    }
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
