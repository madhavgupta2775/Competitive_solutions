#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long


const int MAXN = 200100;
const int MOD = 1000000007;
bool t = true;

void solve() {
    int n; cin >> n;
    if(n%2==0){
        cout << n/2 << endl;
    }
    else if(t){
        cout << ((abs(n-1)/2))*(n/abs(n)) << endl; t = false;
    }
    else{
        cout << ((abs(n+1)/2))*(n/abs(n)) << endl; t = true;
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