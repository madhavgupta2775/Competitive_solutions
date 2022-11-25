#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long

const int MAXN = 200100;
const int MOD = 1000000007;

void solve() {
    int n, x; cin >> n >> x;
    int t = n, j = 0, a = x;
    if(t % x != 0){
        cout << -1 << endl; return;
    }
    else{t /= x;}
    vector<int> v;
    forn(i, 2, t+1){
        if(t % i == 0){
            v.push_back(i);
            t /= i; i--;
        }
    }
    cout << x << " ";
    forn(i, 2, n){
        if(i == x){
            cout << x*v[j] << " ";
            x *= v[j]; j++;
        }
        else{
            cout << i << " ";
        }
    }
    cout << 1 << endl;
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