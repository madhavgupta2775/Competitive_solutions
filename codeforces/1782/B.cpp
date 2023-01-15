#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long
 
const int MOD2 = 1e+7;
const int MOD = 998244353;
 
void solve() {
    int n, ans = 1, count = 0, temp = 0; cin >> n;
    bool t = true;
    vector<int> v(n);
    forn(i, 0, n){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    forn(i, 0, n){
        if(t){
            if(v[i] == 0){
                count++;
            }
            else{
                if(count >= v[i]){
                    count++;
                }
                else{
                    t = false;
                    i--;
                }
            }
        }
        else{
            temp++;
            if((temp + count) > v[i]){
                ans++; count += temp;
                temp = 0; t = true;
            }
        }
    }
    cout << ans << endl;
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