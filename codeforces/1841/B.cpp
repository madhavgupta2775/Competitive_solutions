#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long
#define ff first
#define ss second

// const int MOD2 = 1e9+7;
// const int MOD = 998244353;

void solve() {
    int n, temp = 0, fele = 0; cin >> n;
    bool flag = false;
    vector<int> v;
    forn(i, 0, n){
        cin >> temp;
        if(flag && temp <= fele && temp >= v.back()){
            v.push_back(temp);
            cout << 1; continue;
        }
        else if(flag){
            cout << 0; continue;
        }
        if(i == 0){
            fele = temp;
            v.push_back(temp);
            cout << 1;
        }
        else if(temp >= v.back()){
            v.push_back(temp);
            cout << 1;
        }
        else if(flag == false && temp <= fele){
            v.push_back(temp);
            flag = true;
            cout << 1;
        }
        else{
            cout << 0;
        }
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