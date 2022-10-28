#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl \n

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    for(int i = 1; i <=t; i++){
        string s;
        cin >> s;
        transform(s.begin(), s.end(), s.begin(), ::toupper);
        if(s == "YES"){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    
    return 0;
}