#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long

const int MAXN = 200100;
const int MOD = 1000000007;

void solve() {
    string s; cin >> s;
    if(s.length() == 1){if(s[0] != 'Y' && s[0] != 'e' && s[0] != 's'){
        cout << "NO" << endl; return;
    }}
    forn(i, 0, s.length()-1){
        if(s[i] != 'Y' && s[i] != 'e' && s[i] != 's'){
        cout << "NO" << endl; return;
        }
        if(s[i] == 'e' && s[i+1] != 's'){
            cout << "NO" << endl; return;
        }
        else if(s[i] == 'Y' && s[i+1] != 'e'){
            cout << "NO" << endl; return;
        }
        if(s[i] == 's' && s[i+1] != 'Y'){
            cout << "NO" << endl; return;
        }
    }
    cout << "YES" << endl;
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