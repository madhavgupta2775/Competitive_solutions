#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
    int n, b = 0, j = 0, k = 0; char c; string s; 
    cin >> n >> c >> s;
    vector <int> a, g;
    if(c == 'g'){
        cout << 0 << endl;
        return;
    }
    for(int i = 0; i < n; i++){
        if(s[i] == c){
            a.insert(a.begin() + j, i);
            j++;
        }
        else if(s[i] == 'g'){
            g.insert(g.begin() + k, i);
            k++;
        }                
    }
    for(int i = 0; i < j; i++){
        vector <int>::iterator it = upper_bound(g.begin(), g.end(), a[i]);
        int temp = 0;
        if(it != g.end()){
            temp = (*it) - a[i];
        }
        else{
            temp = (n - a[i] + g[0]);
        }
        if(b < temp){
            b = temp;
        }
    }
    cout << b << endl;
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
