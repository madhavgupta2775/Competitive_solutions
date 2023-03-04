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
    int n, sum = 0; cin >> n;
    vector<int> v(n);
    multiset<int> cards;
    forn(i, 0, n){
        cin >> v[i];
    }
    forn(i, 0, n){
        if(v[i] != 0){
            cards.insert(v[i]);
        }
        else if(cards.empty() == false){
            sum += *cards.rbegin();
            cards.erase(cards.find(*cards.rbegin()));
        }
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
    // solve();
    return 0;
}