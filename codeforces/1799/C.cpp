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
    string s; cin >> s;
    int n = s.size(), p = 0, j = 0, a = 0, count = 0;
    bool done = false;
    vector<int> v(26);
    vector<char> ans(n);
    forn(i, 0, n){
        v[s[i]-97]++;
    }
    while(count < n-1 && done == false){
        if(v[p] == 0){
            p++;
        }
        else if(v[p] > 1){
            v[p] -= 2;
            ans[a] = 'a'+ p; ans[n-a-1] = ans[a]; a++;
            count += 2;
        }
        else{
            while(v[j] == 0 || j == p){
                j++;
            }
            if(v[j] == n - count - 1 && v[j] > 1){
                v[j] -= 2; 
                ans[a] = 'a' + j; ans[n-a-1] = ans[a];
            }
            else{
                v[j]--; v[p]--;
                ans[a] = 'a' + j; ans[n-a-1] = 'a' + p; 
                done = true;
            }
            a++;
            count += 2;
        }
    }
    while(count < n){
        while(v[p] == 0){
            p++;
        }
        ans[a] = p + 'a'; v[p]--; a++;
        count++;
    }
    forn(i, 0, n){
        cout << ans[i];
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