#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long

const int MAXN = 200100;
const int MOD = 1000000007;

void solve() {
    int n, mx = 0, sum = 0; cin >> n;
    vector <int> a(n), b(n);
    forn(i, 0, n){
        cin >> a[i];
    }
    forn(i, 0, n){
        cin >> b[i];
        mx = max(mx, b[i]);
    }
    for(int i = n-1; i >= 0; i--){
        if(b[i] == mx){
            break;
        }
        else{
            if(i>0){a[i-1] += b[i];}
            sum += a[i]; 
            a.pop_back();
            b.pop_back();
        }
    }
    vector<int>::iterator at, bt;
    at = a.begin();bt = b.begin();
    int t = a.size();
    forn(i, 0, t-1){
        sum += a[i];
        a[i+1] += b[i];
    }
    sum += a[t-1];
    cout << sum << endl;
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