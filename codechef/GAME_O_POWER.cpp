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
    int n, k, h, a; cin >> n >> k >> h >> a;
    vector<int> health(n), attack(n);
    vector<int> damage(n);
    forn(i, 0, n){
        cin >> health[i];
    }
    forn(i, 0, n){
        cin >> attack[i];
    }
    forn(i, 0, n){
        damage[i] = (health[i]/a)*attack[i];
        if(health[i] % a == 0){
            damage[i] -= attack[i];
        }
    }
    sort(damage.begin(), damage.end());
    forn(i, 0, n-k){
        h -= damage[i];
        if(h <= 0){
            cout << "NO" << endl; return;
        }
    }
    cout << "YES" << endl;

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