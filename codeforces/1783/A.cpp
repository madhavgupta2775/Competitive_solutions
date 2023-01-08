#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long
 
const int MAXN = 200100;
const int MOD = 1e9+7;
 
void solve() {
    int n; cin >> n;
    vector<int> v(n);
    forn(i, 0, n){
        cin >> v[i];
    }
    sort(v.begin(), v.end(), greater<int>());
    if(v[0] != v.back()){
        cout << "YES" << endl;
        cout << v.back() << " ";
        forn(i, 0, n-1){
            cout << v[i] << " ";
        }
        cout << endl;
    }
    else{
        cout << "NO" << endl;
    }
}
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        solve(); 
    }
    return 0;
}