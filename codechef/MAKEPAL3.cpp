#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long

const int MAXN = 200100;
const int MOD = 1000000007;

void solve() {
    int n, a = 0, min = 0, cu = 0; cin >> n;
    vector<int> v(n);
    forn(i, 0, n){
        cin >> v[i];
    }
    if(v[n-1] > v[0]){ a += v[n-1] -v[0]; min = a;}
    forn(i, 1, n/2){
        if(v[n-1-i] > v[i]){
            cu = v[n-1-i] - v[i];
            if(cu > min){a+= cu-min; min = cu;}
            else{min = cu;}
        }
        else{min = 0;}
    }
    forn(i, n/2 + n%2, n){
        if(v[n-i-1] > v[i]){
            cu = v[n-1-i] - v[i];
            if(cu > min){a+= cu-min; min = cu;}
            else{min = cu;}
        }
        else{min = 0;}
    }
    cout << a << endl;
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