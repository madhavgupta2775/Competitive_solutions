#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
    int a, b, c; cin >> a >> b >> c;
    int d = a + b, e = b + c, f = a + c;
    if(d == c){
        cout << "yes\n";
    }
    else if(e == a){
        cout << "yes\n";
    }
    else if(f == b){
        cout << "yes\n";
    }
    else{
        cout << "no\n";
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    for(int i = 0; i < t; i++){
        solve();
    }
    
    return 0;
}