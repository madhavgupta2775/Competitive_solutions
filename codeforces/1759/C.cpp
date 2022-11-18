#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long

const int MAXN = 200100;
const int MOD = 1000000007;

void solve() {
    int l, r, x; cin >> l >> r >> x;
    int a, b, c = 0; cin >> a >> b;
    if(a == b){cout << 0 << endl; return;}
    if(b > r || b < l){cout << -1 << endl; return;}
    else{
        if(a+x > r && a-x < l){
            cout << -1 << endl;
        }
        else{
            if(b> a && a+x <= b){
                cout << 1 << endl;
            }
                else if(b> a && a-x >= l){
                    cout << 2 << endl;
                }
                else if(b> a && r-b >= x){
                cout << 2 << endl;
                }
                else if(b> a && a+x <= r && b-l >= x){
                    cout << 3 << endl;
                }
                else if(a > b && a-x >= b){
                    cout << 1 << endl;
                }
                else if(a > b && a+x <= r){
                    cout << 2 << endl;
                }
                else if(a > b && b-l >= x){
                    cout << 2 << endl;
                }
                else if(a > b && a-x >= l && r-b >= x){
                    cout << 3 << endl;
                }
            else{ cout << -1 << endl;}
        }
        
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