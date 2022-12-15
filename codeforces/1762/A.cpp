#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long
#define vi vector<int>

const int MAXN = 200100;
const int MOD = 1000000007;

void solve() {
    int n, a = MAXN, b = 1, sum = 0; cin >> n;
    vector<int> v(n);
    forn(i, 0, n){
        cin >> v[i];
        sum += v[i];
    }
    if(sum%2!=0){
        forn(i, 0, n){
            while((v[i] -  v[i]/2)%2==0){
                b++; v[i]/=2;
            }
            if(a>b){
                a = b;
            }
            b= 1;
        }
        cout << a << endl;
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
