#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
    int n; cin >> n;
    vector <int> v(n);
    map <int, char> m;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        m[v[i]] = '.';
    }
    string s, b; cin >> s;
    for(int i = 0; i < n; i++){
        if(m[v[i]] == '.'){
            m[v[i]] = s[i];
            b += m[v[i]];
        }
        else{
            b+= m[v[i]];
        }
    }
    if(b == s){
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
