#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long
#define ull unsigned long long

const int MOD = 998244353;

void solve() {
    int n; cin >> n;
    vector<int> a(n); forn(i, 0, n) cin >> a[i];
    vector<int> powers_of_two(63, 1);
    forn(i, 1, 63) powers_of_two[i] = powers_of_two[i-1] * 2;
    int op = 0, curr = 0, temp = 0, index = 0; bool flag = false;
    forn(i, 1, n) {
        flag = false;
        if(a[i-1] < a[i]) {
            temp = a[i] / a[i-1]; flag = true;
        }
        else temp = a[i-1] / a[i];
        if(!flag) {
            index = lower_bound(powers_of_two.begin(), powers_of_two.end(), temp) - powers_of_two.begin();
            int r = a[i] * (1ll<<index);
            if(r < a[i-1]) {
                index++;
            }
        }
        else {
            index = upper_bound(powers_of_two.begin(), powers_of_two.end(), temp) - powers_of_two.begin();
            index--;
            index *= -1;
        }
        curr = max(0ll, curr + index);
        op += curr;
    }
    cout << op << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(30);
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        solve();
    }
    return 0;
}
