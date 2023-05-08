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
    int n, maxa = 0, maxb = 0; cin >> n;
    vector<int> aaa(n), bbb(n);
    forn(i, 0, n){
        cin >> aaa[i];
    }
    forn(i, 0, n){
        cin >> bbb[i];
        if(aaa[i] > bbb[i]){
            swap(aaa[i], bbb[i]);
        }
        maxa = max(maxa, aaa[i]);
        maxb = max(maxb, bbb[i]);
    }
    if(maxa == aaa[n-1] && maxb == bbb[n-1]){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}   
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    // cout << setprecision(30);
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        solve(); 
    }
    return 0;
}