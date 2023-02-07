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
    int n, c, d, temp = 0; cin >> n >> c >> d;
    vector<int> v(n), psum(n);
    forn(i, 0, n){
        cin >> v[i];
    }
    sort(v.begin(), v.end(), greater<int>());
    if(v[0]*d < c){
        cout << "Impossible" << endl; return;
    }
    forn(i, 0, n){
        if(i == 0){
            psum[i] = v[i];
        }
        else{
            psum[i] = psum[i-1]+v[i];
        }
    }
    if(psum[min(n-1, d-1)] >= c){
        cout << "Infinity" << endl;
        return;
    }
    for(int i = d-1; i >= 0; i--){
        temp = psum[min(n-1, i)]*(d/(i+1));
        if(d%(i+1)){
            temp += psum[min(n-1, max((d%(i+1))-1, 0ll))];
        }
        if(temp >= c){
            cout << i << endl; return;
        }
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