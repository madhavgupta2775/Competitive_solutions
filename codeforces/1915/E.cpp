#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

void solve() {
    int n; cin >> n;
    int sum = 0;
    bool flag = false;
    set<int> s;
    vector<int> v;
    forn(i,0,n) {
        int x; cin >> x;
        v.push_back(x);
        if(flag) continue;
        if(i % 2) {
            sum -= x;
        } else {
            sum += x;
        }
        if(s.find(sum) != s.end() || sum == 0) {
            flag = true;
        }
        s.insert(sum);
    }
    s.clear(); sum = 0;
    forn(i,0,n) {
        if(flag) break;
        if(i % 2) {
            sum += v[i];
        } else {
            sum -= v[i];
        }
        if(s.find(sum) != s.end() || sum == 0) {
            flag = true;
        }
        s.insert(sum);
    }
    if(!flag) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
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