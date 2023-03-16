#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long
#define ff first
#define ss second

const int MOD2 = 1e9+7;
const int MOD = 998244353;

void solve() {
    string a, b, temp; cin >> a >> b;
    if(a[0] == b[0]){
        cout << "YES" << endl;
        cout << a[0] << '*' << endl;
    }
    else if(a[a.size()-1] == b[b.size() -1]){
        cout << "YES" << endl;
        cout << '*' << a[a.size() -1] << endl;
    }
    else{
        forn(i, 0, a.size()-1){
            temp = ""; temp.push_back(a[i]); temp.push_back(a[i+1]);
            if(b.find(temp) != string::npos){
                cout << "YES" << endl;
                cout << '*' << temp << '*' << endl; return;
            }
        }
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
    // solve();
    return 0;
}