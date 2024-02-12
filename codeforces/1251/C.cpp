#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long
#define ull unsigned long long

const int MOD = 998244353;

void solve() {
    string s; cin >> s; int n = s.size();
    vector<int> number(n); forn(i, 0, n) number[i] = s[i] - '0';
    int lp = 0, rp = 0; vector<int> shifts(n), inserts;
    // minimize given number by swapping adjacent digits if they are of different parity
    int parity = number[0] % 2;
    while(rp < n) {
        if(number[rp] % 2 == parity) {
            rp++;
        } 
        else {
            // find the digit greater than number[rp] and swap it with number[rp]
            while(lp < rp && number[lp] <= number[rp]) lp++;
            if(lp == rp) {
                // change parity
                parity = 1 - parity;
                rp++;
                continue;
            }
            // shift all digits from lp to rp to the right by 1
            shifts[lp]++; shifts[rp]--; inserts.push_back(number[rp]);
            rp++;
        }
    }
    // apply the shifts and inserts
    int carry = 0, index = 0;
    forn(i, 0, n) {
        if(shifts[i] > 0) {
            carry += shifts[i];
            while(carry > 0) {
                cout << inserts[index++];
                carry--;
            }
            shifts[i] = 0; i--;
        }
        else if(shifts[i] < 0) {
            continue;
        }
        else {
            cout << number[i];
        }
    }
    cout << endl;
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
