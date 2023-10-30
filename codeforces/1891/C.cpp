#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long


void solve() {
    int n, net_sum = 0; cin >> n;
    vector<int> a(n), zero(n, 0);
    forn(i,0,n) {
        cin >> a[i];
        net_sum += a[i];
    }
    sort(a.begin(), a.end());
    int p = n-1, moves = 0, counter = 0, index = 0;
    while(net_sum > 0) {
        if(a[p] == counter || (p == index && a[p] - counter == 1 && counter != 0)){
            moves++;
            a[p] -= counter;
            counter = 0;
            while(a[p] == 0 && p >= 0) {
                p--;
            }
            if(p < 0) {
                break;
            }
        }
        else{
            if(index != p || (index == p && a[p] - counter == 1)) {
                int temp = min(a[p] - counter, a[index]);
                counter += temp;
                moves += temp;
                a[index] -= temp;
                if(a[index] == 0) {
                    index++;
                }
            }
            else {
                int temp = (a[p] - counter) / 2;
                counter += temp;
                moves += temp;
                a[index] -= temp;
                if(a[index] == 0) {
                    index++;
                }
            }
        }
        if(index > p) {
            break;
        }
    }
    cout << moves << endl;
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