#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

const int MOD = 1e9 + 7;

void solve() {
    int m, x; cin >> m >> x;
    priority_queue<int> pq;
    vector<int> a(m);
    int sum = 0;
    forn(i, 0, m) cin >> a[i];
    forn(i, 0, m) {
        if(i * x >= a[i]) {
            if((i * x) - sum >= a[i]) {
                sum += a[i];
                pq.push(a[i]);
            }
            else if(pq.size() > 0 && pq.top() > a[i]) {
                sum -= pq.top();
                pq.pop();
                sum += a[i];
                pq.push(a[i]);
            }
        }
    }
    cout << pq.size() << endl;
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
