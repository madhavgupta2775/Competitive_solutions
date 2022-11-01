#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
    int a , b, c, d, pos = 0; cin >> a >> b >> c >> d;
    if(b>a){ pos++;}
    if(c>a){ pos++;}
    if(d>a){ pos++;}
    cout << pos << endl;
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