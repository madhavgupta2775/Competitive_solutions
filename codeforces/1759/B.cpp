#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long

const int MAXN = 200100;
const int MOD = 1000000007;

void solve() {
    int n, sum, j = 1; cin >> n >> sum;
    vector<int> v(n);
    map<int, bool> m;
    forn(i, 0, n){
        cin >> v[i];
        m[v[i]] = true;
    }
    while(sum != 0){
        if(m[j]){
            j++;
        }
        else if(sum - j >=0){
            sum -= j;
            m[j] = true; j++;
        }
        else{
            cout << "NO" << endl;
            return;
        }
    }
    forn(i, 1, m.size() + 1){
        if(!m[i]){cout << "NO" << endl;
        return;}
    }
    cout << "YES" << endl;
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