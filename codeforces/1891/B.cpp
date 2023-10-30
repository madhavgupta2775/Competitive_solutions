#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

int highest_power_2(int n) {
    int ans = 0;
    while(n > 0) {
        n /= 2;
        ans++;
    }
    return ans;
}

long long binpow(long long a, long long b, long long m) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n), x(q), count(31, 0);
    vector<int> first_occ(31, -1);
    forn(i,0,n) cin >> a[i];
    forn(i, 0, q) {
        cin >> x[i];
        count[x[i]]++;
        if(first_occ[x[i]] == -1) {
            first_occ[x[i]] = i;
        }
    }
    forn(i, 0, n) {
        int temp = highest_power_2(a[i]);
        vector<pair<int, int>> v;
        for(int j = 0; j <= temp; j++) {
            if(first_occ[j] != -1) {
                v.push_back({first_occ[j], j});
            }
        }
        sort(v.begin(), v.end());
        for(int j = 0; j < v.size(); j++) {
            if(a[i] % binpow(2, v[j].second, 1e9 + 7) == 0) {
                a[i] += binpow(2, v[j].second-1, 1e9 + 7);
            }
        }
    }
    forn(i, 0, n) {
        cout << a[i] << " ";
    }
    cout << endl;
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