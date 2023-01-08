#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long
 
const int MAXN = 200100;
const int MOD = 1e9+7;
 
void solve() {
    int n, a = 1, b = 0, c = 1; cin >> n;
    bool t = true;
    b = n*n;
    vector<vector<int>> v(n, vector<int>(n));
    vector<int> u(n);
    forn(i, 0, n){
        if(t){
            for(int j = 0; j < n; j++){
                u[j] = c;
                if(c == a){
                    c = b; a++;
                }
                else{
                    c = a; b--;
                }
            }
            t = false;
        }
        else{
            for(int j = n-1; j >= 0; j--){
                u[j] = c;
                if(c==a){
                    c = b; a++;
                }
                else{
                    c = a; b--;
                }
            }
            t = true;
        }
        for(int j = 0; j < n; j++){
            cout << u[j] << " ";
        }
        cout << endl;
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