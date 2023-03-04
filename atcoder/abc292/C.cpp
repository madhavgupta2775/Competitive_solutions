#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long
#define ff first
#define ss second

const int MOD2 = 1e9+7;
const int MOD = 998244353;
int countWays(int n)
{
    // To store count of such pairs
    int count = 0;
  
    // Counting number of pairs
    // upto sqrt(n) - 1
    for (int i = 1; i * i <= n; i++)
        if (n % i == 0){
            if(n/i == i){
                count++;
            }
            else{
                count+=2;
            }
        }    
    // To return count of pairs
    return count;
}

void solve() {
    int n, sum = 0; cin >> n;
    vector<int> v(n+1, -1);
    forn(i, 1, n){
        if(v[i] == -1){
            v[i] = countWays(i);
        }
        if(v[n-i] == -1){
            v[n-i] = countWays(n-i);
        }
        sum += v[i]*v[n-i];
    }
    cout << sum << endl;
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