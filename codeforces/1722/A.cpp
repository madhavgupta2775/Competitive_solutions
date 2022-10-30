#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
    int leng; cin >> leng;
    string s; cin >> s;
    sort(s.begin(), s.end());
    if(s == "Timru"){
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