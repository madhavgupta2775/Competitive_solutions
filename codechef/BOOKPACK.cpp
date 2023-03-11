#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
    int a, b, c, n = 0; cin >> a >> b >> c;
    for(int i = 0; i < a; i++){
        if(b % c != 0){
            n += (b / c + 1);
        }
        else{
            n += b/c;
        }
    }
    cout << n << endl;
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