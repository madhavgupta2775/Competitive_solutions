#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long
 
const int MOD2 = 1e9+7;
const int MOD = 998244353;
vector<int> fact;

void solve() {
    int n, ans = 1; cin >> n;
    if(n==1){
        cout << 0 << endl;
    }
    else{
        cout << (fact[n]*(n*(n-1)%MOD2))%MOD2 << endl;
    }
}   
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    forn(i, 0, 1e5+1){
        if(i == 0){
            fact.push_back(0);
        }
        else if(i == 1){
            fact.push_back(1);
        }
        else{
            fact.push_back((i*fact[i-1])%MOD2);
        }
    }
    for(int I = 1; I <= T; I++) {
        solve(); 
    }
    return 0;
}