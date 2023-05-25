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
    int n, scolors = 1, temp = 0, opens = 0, closes = 0; cin >> n;
    vector<int> v(n);
    bool inverted = false, ansinv = false;
    string s; cin >> s;
    if(n%2){
        cout << -1 << endl;
        return;
    }
    forn(i, 0, n){
        if(s[i] == '('){
            temp++;
        }
        else{
            temp--;
        }
        v[i] = 1;
        if(temp < 0){
            inverted = true;
        }
    }
    if(temp){
        cout << -1 << endl;
        return;
    }
    if(inverted){
        forn(i, 0, n){
            if(s[i] == ')'){
                temp++;
            }
            else{
                temp--;
            }
            v[i] = 1;
            if(temp < 0){
                scolors = 2;
                break;
            }
        }
    }
    temp = 0;
    cout << scolors << endl;
    if(scolors == 2){
        forn(i, 0, n){
            if(s[i] == '('){
                temp++;
                v[i] = 1;
            }
            else{
                if(temp == 0){
                    v[i] = 2;
                    closes++;
                }
                else{
                    v[i] = 1;
                    temp--;
                }
                
            }
        }
        forn(i, 0, n){
            if(s[i] == '('){
                if(n/2 - opens == closes){
                    v[i] = 2;
                }
                else{
                    opens++;
                }
            }
        }
    }
    forn(i, 0, n){
        cout << v[i] << " ";
    }
    cout << endl;
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