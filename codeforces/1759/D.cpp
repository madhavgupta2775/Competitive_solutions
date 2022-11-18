#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long

const int MAXN = 200100;
const int MOD = 1000000007;

void solve() {
    int n, m, a = 1, b = 1; cin >> n >> m;
    int too = 0, fi = 0, tto = 0, ffi = 0;
    while(n%2 == 0){too++; n /= 2;tto++;}
    while(n%5 == 0){fi++; n /= 5;ffi++;}
    while(too > fi && m >= pow(5, b)){
        fi++; b++;
    }
    while(fi > too && m >= pow(2, a)){
        too++; a++;
    }
    while(m >= pow(5, b)*pow(2, a) && fi == too){
        too++;fi++;a++;b++;
    }
    if(a == 1 && b == 1){ n*= pow(2,tto); n*= pow(5, ffi);cout << n*m << endl; return;}
    n *= pow(2, max(min(fi, too), tto));
    n *= pow(5, max(min(fi, too), ffi));
    int temp = m/(pow(5, b-1)*pow(2, a-1));
    n *= temp;
    cout << n << endl;
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