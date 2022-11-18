#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long

const int MAXN = 200100;
const int MOD = 1000000007;
int ins(vector<int> &a,int  wan, int n){
    forn(i, 0, n){
        cin >> a[i];
        if(a[i] == 1){wan++;}
    }
    return wan;
}

void solve() {
    int n, wan = 0, too = 0, t = 0; cin >> n;
    vector<int> a(n), b(n);
    wan = ins(a, wan, n);
    too = ins(b, too, n);
    forn(i, 0, n){
        if(a[i] != b[i] && wan != too){
            t++; wan-too>0?wan--:too--;
        }
        else if(a[i] != b[i] && wan == too){
            t++; break;
        }
    }
    cout << t << endl;
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