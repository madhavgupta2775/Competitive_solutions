#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
    string s; cin >> s;
    int a = 0;
    for(int i = 0; i < 3; i++){
        a += s[i];
    }
    for(int i = 3; i < 6; i++){
        a -= s[i];
    }
    if(a == 0){
        cout << "yes" << endl;
    }
    else{
        cout << "no\n";
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