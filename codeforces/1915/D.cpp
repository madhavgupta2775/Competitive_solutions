#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

void solve() {
    int n; cin >> n;
    string s, inp; cin >> s; inp = s;
    string ans;
    forn(i, 0, n) {
        if(s[i] == 'a' || s[i] == 'e') {
            s[i] = 'V';
        }
        else {
            s[i] = 'C';
        }
    }
    bool flag = false;
    forn(i, 0, n) {
        if(s[i] == 'V') {
            if(i < n-1 && (s[i+1] == 'C' && s[i+2] == 'C')) {
                ans += "V";
                flag = true;
            }
            else if(i == n-2 && s[i+1] == 'C') {
                ans += "V";
                flag = true;
            }
            else {
                ans += "V.";
                flag = false;
            }
        }
        else {
            if(flag) {
                ans += "C.";
                flag = false;
            }
            else {
                ans += "C";
            }
        }
    }
    int index = 0;
    forn(i, 0, ans.size()) {
        if(ans[i] != '.') {
            ans[i] = inp[index];
            index++;
        }
        
    }
    ans.pop_back();
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