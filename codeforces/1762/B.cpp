#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long
 
const int MAXN = 200100;
const int MOD = 99244353;
long long bp(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
vector<int> pow2;
 
void solve() {
    int n, a; cin >> n;
    cout << n << endl;
    forn(i, 0, n){
        cin >> a;
        cout << i+1 << " "<< pow2[lower_bound(pow2.begin(), pow2.end(), a)-pow2.begin()] - a << endl;
    }
}
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    int temp =1; pow2.push_back(1);
    while(temp< 1e9){
        temp<<=1;
        pow2.push_back(temp);
    }
    for(int I = 1; I <= T; I++) {
        solve(); 
    }
    return 0;
}