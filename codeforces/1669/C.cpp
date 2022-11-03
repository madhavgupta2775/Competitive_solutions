#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
bool oe(int a[], int wan, int n, int i){
    for(i; i < n; i+= 2){
        if(a[i] % 2 != wan){
            return false;
        }
    }
    return true;
}
void solve(){
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int wan = (a[0] % 2);
    int too = (a[1] % 2);
    if(oe(a, wan, n, 0) && oe(a, too, n, 1)){
        cout << "YES\n"; return;
    }
    cout << "NO\n";
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