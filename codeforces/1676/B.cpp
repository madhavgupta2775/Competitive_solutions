#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
    int n, m, c = 0; cin >> n; vector <int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        if(i == 0){
            m = v[i];
        }
        if(v[i] < m){
            c += (m-v[i])*i;
            m = v[i];
        }
        else if(v[i] > m){
            c += (v[i] - m);
        }
    }
    cout << c << endl;
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