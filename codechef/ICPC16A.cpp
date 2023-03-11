#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long
#define ff first
#define ss second

const int MOD2 = 1e9+7;
const int MOD = 998244353;

void solve() {
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    if(abs(x1 - x2) == 0){
        if(y1>y2){
            cout << "down" << endl;
        }
        else{
            cout << "up" << endl;
        }
    }
    else if(abs(y1-y2) == 0){
        if(x1>x2){
            cout << "left" << endl;
        }
        else{
            cout << "right" << endl;
        }
    }
    else{
        cout << "sad" << endl;
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
    //  solve();
    return 0;
}