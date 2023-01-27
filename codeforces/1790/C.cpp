#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long

const int MOD2 = 1e9+7;
const int MOD = 998244353;

void solve() {
    int n, temp = 0, sum = 0; cin >> n;
    sum = (n*(n+1))/2;
    vector<map<int, int>> v(n-1);
    vector<int> per(n-1);
    forn(i, 0, n){
        for(int j = 0; j < n-1; j++){
            cin >> temp;
            v[j][temp]++;
        }
    }
    for(int i = n-2; i >= 0; i--){
        for(auto it : v[i]){
            if(it.second == n-i-1){
                if(i == n-2){
                    per[i] = it.first;
                    sum -= per[i];
                }
                else if(per[i+1] != it.first){
                    per[i] = it.first;
                    sum -= per[i];
                }
            }
        }
    }
    forn(i, 0, n-1){
        cout << per[i] << " ";
    }
    cout << sum << endl;
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