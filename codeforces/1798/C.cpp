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
    int n, prev_lcm = 0, prev_gcd = 0, tags = 0; cin >> n;
    vector<pair<int, int>> candies(n);
    forn(i, 0, n){
        cin >> candies[i].ff >> candies[i].ss;
    }
    forn(i, 0, n){
        if(!prev_gcd){
            if(i == n-1){
                tags++; break;
            }
            prev_lcm = lcm(candies[i].ss, candies[i+1].ss);
            prev_gcd = gcd(candies[i].ff*candies[i].ss, candies[i+1].ff*candies[i+1].ss);
            if(prev_gcd % prev_lcm != 0){
                prev_gcd = 0; prev_lcm = 0;
            }
            tags++;
        }
        else{
            if(i == n-1){
                break;
            }
            //if(prev_gcd % candies[i+1].ss != 0 || candies[i+1].ss * candies[i+1].ff % prev_gcd != 0){
            prev_lcm = lcm(prev_lcm, candies[i+1].ss); prev_gcd = gcd(prev_gcd, candies[i+1].ss*candies[i+1].ff);
            if(prev_gcd % prev_lcm != 0){
                prev_gcd = 0; prev_lcm = 0;
            }
        }
    }
    cout << tags << endl;
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