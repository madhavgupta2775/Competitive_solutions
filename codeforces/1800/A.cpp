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
    int n, t = 0; cin >>n;
    string s; cin >> s;
    forn(i, 0, n){
        if((s[i] == 'm' || s[i] == 'M')){
            if(t == 0){
                t++;
            }
            else if(t != 1){
                cout << "NO" << endl; return;
            }
        }
        else if(s[i] == 'e' || s[i] == 'E'){
            if(t == 1){
                t++;
            }
            else if(t != 2){
                cout << "NO" << endl; return;
            }
        }
        else if(s[i] == 'o' || s[i] == 'O'){
            if(t == 2){
                t++;
            }
            else if(t != 3){
                cout << "NO" << endl; return;
            }
        }
        else if(s[i] == 'w' || s[i] == 'W'){
            if(t == 3){
                t++;
            }
            else if(t != 4){
                cout << "NO" << endl; return;
            }
        }
        else{
            cout << "NO" << endl; return;        
        }
    }
    if(t == 4)cout << "YES" << endl;
    else{
        cout << "NO" << endl;
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
    // solve();
    return 0;
}