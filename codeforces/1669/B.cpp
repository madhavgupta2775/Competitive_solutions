#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
    int n, tem, a = 0; cin >> n;
    map <int, int> mn;
    for(int i = 0; i < n; i++){
        cin >> tem;
        mn[tem] += 1;
        if((mn[tem] >= 3) && a == 0){
            a = tem;
        }
    }
    if(a != 0){
        cout << a << endl;
    }
    else{
        cout << -1 << endl;
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