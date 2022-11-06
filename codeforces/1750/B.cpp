#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
    int n, x = 0, y = 0, tx = 0, ty = 0; cin >> n;
    map <char, int> m;
    string s; cin >> s; char tt = s[0];
    for(int i = 0; i < n; i++){
        if(s[i] == '0'){
            x++;
            if(tt == '1'){
                if(m['1'] < ty){
                    m['1'] = ty;
                }
                ty = 0; tt = '0';
            }
            tx++;
        }
        else{
            y++;
            if(tt == '0'){
                if(m['0'] < tx){
                    m['0'] = tx;
                }
                tx = 0; tt = '1';
            }
            ty++;
        }
    }
    m['0'] = max(m['0'], tx);
    m['1'] = max(m['1'], ty);
    int ma = max(m['0']*m['0'], m['1']*m['1']);
    cout << max(ma, x*y) << endl;
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
