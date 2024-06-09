#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<int> digits, num1, num2;
    int temp = n;
    while(n) {
        digits.push_back(n % 10);
        n /= 10;
    }
    reverse(digits.begin(), digits.end());
    if(digits[0] != 1 || digits.back() == 9) {
        cout << "NO" << endl;
        return;
    }
    while(temp) {
        if(temp % 10 == 9 || temp < 10) {
            cout << "NO" << endl;
            return;
        }
        int tbd = temp % 10 + 10; temp -= tbd;
        num1.push_back(max(5ll, tbd - 9));
        tbd -= num1.back();
        num2.push_back(tbd);
        temp /= 10;
    }
    cout << "YES" << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
