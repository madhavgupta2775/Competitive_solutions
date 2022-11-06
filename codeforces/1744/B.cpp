#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
    int n, q, z = 0, o = 0, s = 0; cin >> n >> q;
    vector <int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i]; s += v[i];
        if(v[i] % 2 == 0){
            z++;
        }
        else{
            o++;
        }
    }
    for(int i = 0; i < q; i++){
        int p, x; cin >> p >> x;
        if(p == 0){
            s += z*x;
            if(x % 2 != 0){
                o += z; z = 0;
            }
        }
        else{
            s += o*x;
            if(x % 2 != 0){
                z += o; o = 0;
            }  
        }
    cout << s << endl;
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
