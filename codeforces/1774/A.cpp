#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long
 
const int MAXN = 200100;
const int MOD = 998244353;
 
void solve() {
    int n, sum = 0, a = 0; string s; 
    cin >> n >> s;
    sum += s[0] - '0';
    forn(i, 1, n){
        a = s[i] - '0';
        if(sum > 0){
            cout << '-';
            sum -= a;
        }
        else{
            cout << '+';
            sum += a;
        }
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
    return 0;
}