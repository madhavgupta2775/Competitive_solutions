#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long
#define ff first
#define ss second

const int MOD2 = 1e9+7;
const int MOD = 998244353;

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void solve() {
    int l, n1, n2,a = 0, b = 0, ans = 0; cin >> l >> n1 >> n2;
    vector<pair<int, int>> one(n1), two(n2);
    forn(i, 0, n1){
        cin >> one[i].first >> one[i].second;
    }
    forn(i, 0, n2){
        cin >> two[i].first >> two[i].second;
    }
    int i = 0, j = 0;
    while(i != n1 && j != n2){
        if(one[i].first == two[j].first){
            ans += min(min(one[i].second+a,two[j].second + b) - a, min(one[i].second+a,two[j].second + b) - b);
        }
        if(a + one[i].second < b + two[j].second){
            a += one[i].second; i++;
        }
        else{
            b += two[j].second; j++;
        }
        // while(a + one[i].second < b){
        //     a += one[i].second;
        //     i++;
        // }
        // while(b + two[j].second < a){
        //     b += two[j].second;
        //     j++;
        // }
    }
    cout << ans << endl;
}   
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    // int T = 1;
    // cin >> T;
    // for(int I = 1; I <= T; I++) {
    //     solve(); 
    // }
    solve();
    return 0;
}