#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
    int cho, can; cin >> cho >> can;
    if(cho*2 > can*5){
        cout << "chocolate" << endl;
    }
    else if(cho*2 < can*5){
        cout << "candy" << endl;
    }
    else{
        cout << "either" << endl;
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