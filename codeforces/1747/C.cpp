#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long

const int MAXN = 200100;
const int MOD = 1000000007;

void solve() {
    int n; cin >> n;
    int a[n]; bool t = false;
    cin >> a[0];
    forn(i, 1, n){
        cin >> a[i];
        if(a[i] < a[0]){
            t = true;
        }
    }
    if(t){
        cout << "Alice" << endl;
    }
    else{
        cout << "Bob" << endl;
    }
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