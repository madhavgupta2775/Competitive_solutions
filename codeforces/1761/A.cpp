#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long

const int MAXN = 200100;
const int MOD = 1000000007;

void solve() {
    int n, a = 0, b = 0;
    cin >> n >> a >> b;
    if(a == b && b == n){
        cout << "Yes" << endl;
        return;
    }
    if(b+a>=n){
        cout << "No" << endl;
    }
    else if(n-a-b == 1){
        cout << "No" << endl;
    }
    else{
        cout << "Yes" << endl;
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