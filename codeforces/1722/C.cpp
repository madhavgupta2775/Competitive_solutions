#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long
#define ff first
#define ss second

const int MOD2 = 1e9+7;
const int MOD = 998244353;
void sieve(int n, vector<bool> primes){
    vector<bool> temp(n, 1);
    forn(i, 2, n+1){
        if(primes[i]==0){
            continue;
        }
        for(int j = i; j <= n; j += i){
            primes[j] = 0;
        }
    }
    primes = temp;
}

void solve() {
    int n, ans = 0; cin >> n;
    vector<vector<string>> v(3, vector<string> (n));
    map<string, int> m;
    for(int j = 0; j < 3; j++){
        forn(i, 0, n){
            cin >> v[j][i];
            m[v[j][i]]++;
        }
    }
    for(int j = 0; j < 3; j++){
        ans = 0;
        forn(i, 0, n){
            if(m[v[j][i]] == 1){
                ans += 3;
            }
            else if(m[v[j][i]] == 2){
                ans++;
            }
        }
        cout << ans << " ";
    }
    cout << endl;
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