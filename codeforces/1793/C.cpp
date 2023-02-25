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
    int n; cin >> n;
    vector<int> v(n);
    forn(i, 0, n){
        cin >> v[i];
    }
    vector<bool> w(n, true);
    int l = 0, r = n-1;
    int maxs = n, mins = 1;
    while(l <= r){
        if(v[l] == mins){
            w[v[l]-1] = false; l++;
        }
        else if(v[l] == maxs){
            w[v[l]-1] = false; l++;
        }
        else if(v[r] == mins){
            w[v[r]-1] = false; r--;
        }
        else if(v[r] == maxs){
            w[v[r]-1] = false; r--;
        }
        else{
            break;
        }
        while(w[mins-1] == false && maxs >= mins){
            mins++;
        }
        while(w[maxs-1] == false && maxs >= mins){
            maxs--;
        }
    }
    if(l > r){
        cout << -1 << endl;
    }
    else{
        cout << l+1 << " " << r+1 << endl;
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
    //solve();
    return 0;
}