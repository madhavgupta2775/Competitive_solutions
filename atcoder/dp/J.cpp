#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

double dp[302][302][302]; // i dishes with 1 sushi, j dishes with 2 sushi, k dishes with 3 sushi

double compute(int i, int j, int k, int n) {
    if(i == 0 && j ==  0 && k == 0) return 0;
    if(dp[i][j][k] > -0.5) return dp[i][j][k];
    dp[i][j][k] = 0; double a = 0, b = 0, c = 0;
    if(i> 0)a = compute(i-1, j, k, n); // expected operations to finish all dishes after choosing a dish with 1 sushi
    if(j>0)b = compute(i+1, j-1, k, n); // expected operations to finish all dishes after choosing a dish with 2 sushi
    if(k>0)c = compute(i, j+1, k-1, n); // expected operations to finish all dishes after choosing a dish with 3 sushi
    double temp = (n/(double)(i + j + k)); 
    if(i > 0)temp += (i*a)/(double)(i + j + k); 
    if(j> 0)temp += (j*b)/(double)(i + j + k); 
    if(k > 0)temp += (k*c)/(double)(i + j + k);
    dp[i][j][k] = temp;
    return dp[i][j][k];
}

void solve() {
    int n; cin >> n;
    vector<int> a(n); forn(i,0,n) cin >> a[i];
    memset(dp, -1, sizeof(dp));
    int one = 0, two = 0, three = 0;
    forn(i,0,n) {
        if(a[i] == 1) one++;
        else if(a[i] == 2) two++;
        else three++;
    }
    cout << compute(one, two, three, n) << endl;
}

 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << setprecision(30);
    int T = 1;
    // cin >> T;
    for(int I = 1; I <= T; I++) {
        solve();
    }
    return 0;
}