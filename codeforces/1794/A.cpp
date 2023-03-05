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
    string sa, sb, temp, s;
    bool fa = true;
    forn(i, 0, 2*n-2){
        if(sa.size() != n-1){
            cin >> sa;
        }
        else if(sb.size() != n-1){
            cin >> sb;
        }
        else{
            cin >> temp;
        }
    }
    forn(i, 0, n-2){
        if(sa[i+1] != sb[i]){
            fa = false; break;
        }
    }
    if(fa){
        s = sa;
        s.push_back(sb.back());
    }
    else{
        s = sb; 
        s.push_back(sa.back());
    }
    temp = s;
    reverse(temp.begin(), temp.end());
    if(temp == s){
        cout <<"YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}   
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        solve(); 
    }
    //  solve();
    return 0;
}