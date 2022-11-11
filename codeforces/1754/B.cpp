#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long

const int MAXN = 200100;
const int MOD = 1000000007;

void solve() {
    int n; cin >> n;
    int a = (n/2 + n%2);
    int b = n, c = a; bool ta = true, tb = true;
    while(ta || tb){
        if(c != 0){
            cout << c << " ";
            c--;
        }
        else{ ta = false;}
        if(b != a){
            cout << b << " ";
            b--;
        }
        else{ tb = false;}
    }
    cout << endl;
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