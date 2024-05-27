#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

const int MOD = 1e9 + 7;

bool check_sorted(vector<int> &a, int start, int end, int n) {
    int prev = a[start];
    for (int i = start + 1; i < n; i++) {
        if (a[i] < prev) return false;
        prev = a[i];
    }
    if(end < start) {
        for (int i = 0; i <= end; i++) {
            if (a[i] < prev) return false;
            prev = a[i];
        }
    }
    return true;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    forn(i, 0, n) cin >> a[i];
    int start = 0, end = n-1;
    while (start < n) {
        if (check_sorted(a, start, end, n)) {
            cout << "YES" << endl;
            return;
        }
        start++;
        end++; end %= n;
    }
    cout << "NO" << endl;
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