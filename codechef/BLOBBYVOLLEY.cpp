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
    int n, pa = 0, pb = 0, sw = 0; cin >> n;
    string s; cin >> s;
    forn(i, 0, n){
        if(sw){
            if(s[i] == 'B'){
                pb++;
            }
            else{
                sw = 0;
            }
        }
        else{
            if(s[i] == 'A'){
                pa++;
            }
            else{
                sw = 1;
            }
        }
    }
    cout << pa << " " << pb << endl;
}   
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    // cout << setprecision(30);
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        solve(); 
    }
    return 0;
}