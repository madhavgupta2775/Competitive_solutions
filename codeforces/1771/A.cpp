#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long


const int MAXN = 200100;
const int MOD = 1000000007;
int gcd(int a, int b) {
    if (!a || !b)
        return a | b;
    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do {
        b >>= __builtin_ctz(b);
        if (a > b)
            swap(a, b);
        b -= a;
    } while (b);
    return a << shift;
}

void solve() {
    int n, a = 1000000, b = 0, c = 0, d= 0; cin >> n;
    vector<int> v(n);
    forn(i, 0, n){
        cin >> v[i];
        if(a == v[i]){
            c++;
        }
        else if(a > v[i]){
            c = 1; a = v[i];
        }
        if(b == v[i]){
            d++;
        }
        else if(v[i] > b){
            d = 1; b = v[i];
        }
    }
    if(b !=a){cout << d*c*2 << endl;}
    else{cout << (d*(d-1)) << endl;}
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