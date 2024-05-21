#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int x = 0, y = 0;
    int north = 0, south = 0, east = 0, west = 0;
    int hor = 0, ver = 0;
    forn(i, 0, n) {
        if(s[i] == 'N') {
            y++; ver++; north++;
        }
        else if(s[i] == 'S') {
            y--; ver++; south++;
        }
        else if(s[i] == 'E') {
            x++; hor++; east++;
        }
        else {
            x--; hor++; west++;
        }
    }
    if(x % 2 || y % 2) {
        cout << "NO" << endl;
        return;
    }
    if( (ver + hor <= 2 && x == 0 && y == 0) ) {
        cout << "NO" << endl;
        return;
    }
    int rover[4] = {north/2, south/2, east/2, west/2};
    int heli[4] = {north - rover[0], south - rover[1], east - rover[2], west - rover[3]};
    if(north == south == east == west == 1) {
        swap(rover[0], heli[0]);
        swap(rover[1], heli[1]);
    }
    map<char, int> mp;
    mp['N'] = 0;
    mp['S'] = 1;
    mp['E'] = 2;
    mp['W'] = 3;
    string ans = "";
    forn(i, 0, n) {
        if(rover[mp[s[i]]]) {
            ans += 'R';
            rover[mp[s[i]]]--;
        }
        else {
            ans += 'H';
        }
    }
    cout << ans << endl;
}


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << fixed << setprecision(30);
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        solve();
    }
    return 0;
}