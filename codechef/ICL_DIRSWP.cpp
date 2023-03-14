#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long
#define ff first
#define ss second

const int MOD2 = 1e9+7;
const int MOD = 998244353;

int check(vector<vector<char>> &v, int a, int b){
    if(v[a][b] == 'L' && b > 0 && v[a][b-1] == 'R'){
        swap(v[a][b], v[a][b-1]);
        return 1 + check(v, a, b) + check(v, a, b-1);
    }
    else if(v[a][b] == 'R' && b < v[a].size()-1 && v[a][b+1] == 'L'){
        swap(v[a][b], v[a][b+1]);
        return 1 + check(v, a, b) + check(v, a, b+1);
    }
    else if(v[a][b] == 'U' && a > 0 && v[a-1][b] == 'D'){
        swap(v[a][b], v[a-1][b]);
        return 1 + check(v, a, b) + check(v, a-1, b);
    }
    else if(v[a][b] == 'D' && a < v.size()-1 && v[a+1][b] == 'U'){
        swap(v[a][b], v[a+1][b]);
        return 1 + check(v, a, b) + check(v, a+1, b);
    }
    else{
        return 0;
    }
}

void solve() {
    int n, m, sum = 0; cin >> n >> m;
    vector<vector<char>> v(n, vector<char> (m));
    forn(i, 0, n){
        for(int j = 0; j < m; j++){
            cin >> v[i][j];
        }
    }
    forn(i, 0, n){
        for(int j = 0; j < m; j++){
            sum += check(v, i, j);
        }
    }
    cout << sum << endl;
}   
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    // int T = 1;
    // cin >> T;
    // for(int I = 1; I <= T; I++) {
    //     solve(); 
    // }
    solve();
    return 0;
}