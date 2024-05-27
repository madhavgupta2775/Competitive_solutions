#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

const int MOD = 1e9 + 7;

int median_of_three(int a, int b, int c) {
    if(a > b) {
        if(b > c) return b;
        else if(a > c) return c;
        else return a;
    } else {
        if(a > c) return a;
        else if(b > c) return c;
        else return b;
    }
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    vector<pair<int, int>> indices(n);
    forn(i, 0, n) {
        cin >> a[i];
        indices[i] = {a[i], i};
    }
    sort(indices.begin(), indices.end());
    for(int i = n-1; i >= 0; i--) {
        // check previous 2 elements and next 2 elements in a of indices[i]
        int idx = indices[i].second;
        if(idx == 0) {
            if(a[idx] <= a[idx+1]) {
                cout << a[idx] << endl;
                return;
            }
        } else if(idx == n-1) {
            if(a[idx] <= a[idx-1]) {
                cout << a[idx] << endl;
                return;
            }
        } else {
            if(a[idx] <= a[idx-1] || a[idx] <= a[idx+1]) {
                cout << a[idx] << endl;
                return;
            }
        }
        if(idx > 1) {
            if(a[idx] <= a[idx-2]) {
                cout << a[idx] << endl;
                return;
            }
        }
        if(idx < n-2) {
            if(a[idx] <= a[idx+2]) {
                cout << a[idx] << endl;
                return;
            }
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}