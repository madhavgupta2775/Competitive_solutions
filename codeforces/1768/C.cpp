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
    int n; cin >> n;
    vector<int> v(n), count(n+1), p(n), q(n);
    vector<bool> occ(n+1);
    set<int> num, num2;
    auto it = num.begin();
    forn(i, 0, n){
        num.insert(i+1);
        num2.insert(i+1);
    }
    forn(i, 0, n){
        cin >> v[i];
        count[v[i]]++;
    }
    forn(i, 1, n+1){
        if(count[i] > 2 || count[1] > 1 || count[n] == 0){
            cout << "NO" << endl;
            return;
        }
    }
    forn(i, 0, n){
        if(occ[v[i]] != true){
            p[i] = v[i]; occ[v[i]] = true;
            if(count[v[i]] == 1){
                q[i] = v[i]; num2.erase(q[i]);
            }
            num.erase(v[i]);
        }
    }
    forn(i, 0, n){
        if(p[i] == 0){
            if(num.lower_bound(v[i]) != num.begin()){
                it = num.lower_bound(v[i]);
                p[i] = *(--it);
                q[i] = v[i];
                num2.erase(q[i]);
                num.erase(it);
            }
            else{
                cout << "NO" << endl; return;
            }
        }
    }
    forn(i, 0, n){
        if(q[i] == 0){
            it = num2.lower_bound(p[i]);
            q[i] = *(--it);
            num2.erase(it);
        }
    }
    cout << "YES" << endl;
    forn(i, 0, n){
        cout << p[i] << " ";
    }
    cout << endl;
    forn(i, 0, n){
        cout << q[i] << " ";
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