#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
    map <int, bool> m; int n, d = 0;
    cin >> n; int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(m[a[i]]){
            d++;
        }
        else{
            m[a[i]] = true;
        }
    }
    if(d % 2 == 0){
        cout << m.size() << endl;
    }
    else{
        cout << m.size() - 1 << endl;
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