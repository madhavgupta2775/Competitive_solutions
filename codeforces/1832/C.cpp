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
    int n, fsize = 0, temp = 0; cin >> n;
    vector<int> v;
    forn(i, 0, n){
        cin >> temp;
        if(i == 0 || v.back() != temp){
            v.push_back(temp);
        }
    }
    fsize = v.size();
    if(v.size() == 1){
        cout << 1 << endl; return;
    }
    forn(i, 1, v.size()-1){
        if(v[i] - v[i-1] > 0 && v[i+1] - v[i] > 0){
            fsize--;
        }
        else if(v[i] - v[i-1] < 0 && v[i+1] - v[i] < 0){
            fsize--;
        }
    }
    cout << fsize << endl;
}   
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    // cout << setprecision(30);
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        solve(); 
    }
    return 0;
}