#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long

const int MAXN = 200100;
const int MOD = 1000000007;

void solve() {
    int n, cp = 0, dp, c = 0, t = 0; cin >>n;
    vector<int> v(n), p(n);
    forn(i, 0, n){
        cin >> v[i]; t = i+1;
        while(v[i] % 2 == 0){cp++; v[i]/= 2;}
        while(t % 2 == 0){p[i]++; t/=2;}
    }
    sort(p.begin(), p.end());
    dp = n - cp;
    if(dp>0){
        int j = n-1;
        while(dp > 0 && p[j]>0){
            dp -= p[j]; j--;c++;
        }
        if(dp <= 0){cout << c << endl;}
        else{cout << -1 << endl;}
    }
    else{
        cout << 0 << endl;
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
    return 0;
}   