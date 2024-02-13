#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long
#define ull unsigned long long

const int MOD = 998244353;

int count_ending_zeros(int x) {
    int cnt = 0;
    while(x % 10 == 0) {
        cnt++;
        x /= 10;
    }
    return cnt;
}

int count_digits(int x) {
    int cnt = 0;
    while(x > 0) {
        cnt++;
        x /= 10;
    }
    return cnt;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n), zeros(20);
    int digit_count = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        zeros[count_ending_zeros(a[i])]++;
        digit_count += count_digits(a[i]);
    }
    forn(i, 0, n) {
        for(int j = 19; j >= 0; j--) {
            if(zeros[j] > 0) {
                zeros[j]--;
                digit_count -= j;
                zeros[0]++;
                break;
            }
        }
        for(int j = 19; j > 0; j--) {
            if(zeros[j] > 0) {
                zeros[j]--;
                break;
            }
        }
    }
    if(digit_count <= m) {
        cout << "Anna" << endl;
    }
    else {
        cout << "Sasha" << endl;
    }
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
