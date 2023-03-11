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
    int n, k, temp = 1; cin >> n >> k;
    vector<vector<int>> v(k, vector<int> (n/k));
    forn(i, 0, k){
        if(i%2==0){
            if(i == 0 || i == k-1){
                for(int j = 0; j < n/k; j++){
                    v[i][j] = temp;
                    temp++;
                }
            }
            else{
                for(int j = 0; j < n/k; j++){
                    v[i][j] = temp;
                    temp += 2;
                }
            }
        }
        else{
            if(i == 0 || i == k-1){
                for(int j= n/k-1; j >=0; j--){
                    v[i][j] = temp;
                    temp++;
                }
            }
            else{
                for(int j = n/k-1; j >=0; j--){
                    v[i][j] = temp;
                    temp+= 2;
                }
            }
        }
    }
    forn(i, 0, n/k){
        for(int j = 0; j < k; j++){
            cout << v[j][i] << " ";
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
    // solve();
    return 0;
}