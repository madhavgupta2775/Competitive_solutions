#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
string rep(string r){
    for(int i = 0; i < r.length(); i++){
        if(r[i] == 'G'){
            r[i] = 'B';
        }
    }
    return r;
}
void solve(){
    int col; cin >> col;
    string rone, rtwo; cin >> rone >> rtwo;
    rone = rep(rone); rtwo = rep(rtwo);
    if(rone == rtwo){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << setprecision(2) << fixed;
    int t; cin >> t;
    for(int i = 0; i < t; i++){
        solve();
    }
    
    return 0;
}