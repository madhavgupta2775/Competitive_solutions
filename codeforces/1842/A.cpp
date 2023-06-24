#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long
#define ff first
#define ss second
#define pb push_back

// const int MOD2 = 1e9+7;
// const int MOD = 998244353;

void solve() {
    int n, m, suma = 0, sumb = 0; cin >> n >> m;
    vector<int> a(n), b(m);
    forn(i, 0, n){
        cin >> a[i];
        suma += a[i];
    }
    forn(i, 0, m){
        cin >> b[i];
        sumb += b[i];
    }
    if(suma > sumb){
        cout << "Tsondu" << endl;
        return;
    }
    else if(suma < sumb){
        cout << "Tenzing" << endl;
        return;
    }
    else{
        cout << "Draw" << endl;
        return;
    }
}   
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << setprecision(30);
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        solve(); 
    }
    return 0;
}