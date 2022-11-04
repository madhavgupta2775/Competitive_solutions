#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
    int n; cin >> n;
    int i = 0;
    cout << n/2 + n%2 << endl;
    while(3*(n - 2*i) > 2){
        cout << 2 + 3*i << " " << 3*(n-i) << endl;
        i++;
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