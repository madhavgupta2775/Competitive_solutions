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
    int n; cin >> n;
    vector<int> v(n);
    forn(i, 0, n){
        cin >> v[i];
    }
    int lp = 0, rp = 0, count = 0;
    while(lp < n){
        if(lp == 0 || v[lp-1] > v[lp]){
            if(rp == n-1 || v[rp] < v[rp+1]){
                count++; lp = max(lp+1, rp+1); rp = lp; 
            }
            else{
                if(v[rp+1] == v[rp]){
                    rp++;
                }
                else{
                    lp = max(rp, lp+1); rp = lp;
                }
            }
        }
        else{
            lp = max(rp, lp+1); rp = lp;
        }
    }
    if(count == 1){
        cout << "YES" << endl;
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
    //solve();
    return 0;
}