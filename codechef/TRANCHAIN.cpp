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
    int n; cin >> n; string temp;
    vector<int> a(4);
    forn(i, 0, n){
        cin >> temp;
        if(temp == "O"){
            a[0]++;
        }
        else if(temp == "A"){
            a[1]++;
        }
        else if(temp == "B"){
            a[2]++;
        }
        else{
            a[3]++;
        }
    }
    cout << a[0] + max(a[1], a[2]) + a[3] << endl;
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