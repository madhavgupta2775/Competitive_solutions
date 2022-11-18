#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long

const int MAXN = 200100;
const int MOD = 1000000007;

void solve() {
    int n; cin >> n;
    bool t = false;
    vector<int> v(n), b(n+1);
    cin >> v[0]; b[0] = v[0];
    forn(i, 0, n-1){
        cin >> v[i+1];
        if(i != n-1){
            b[i+1] = lcm(v[i+1], v[i]);
            if(v[i] != gcd(b[i+1], b[i])){
                t = true;            
            }
        }
        else{
            if(b[i+1]%v[i+1] != 0){
                t = true;
            }
        }
    }
    if(t){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
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