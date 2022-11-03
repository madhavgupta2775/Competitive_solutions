#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
    int r; cin >> r;
    if(r <= 1399){
        cout << "Division 4" << endl;
    }
    else if(r <= 1599){
        cout << "Division 3" << endl;
    }
    else if(r <= 1899){
        cout << "Division 2" << endl;
    }
    else{
        cout << "Division 1" << endl;
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