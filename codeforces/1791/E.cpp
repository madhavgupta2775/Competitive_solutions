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
    int n, cn = 0, sum = 0; cin >> n;
    vector<int> v(n);
    forn(i, 0, n){
        cin >> v[i];
        if(v[i] < 0){
            cn++;
        }
        v[i] = abs(v[i]);
        sum += v[i];
    }
    sort(v.begin(), v.end());
    if(cn%2){
        cout << sum - 2*v[0] << endl; return;
    }
    else{
        cout << sum << endl;
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