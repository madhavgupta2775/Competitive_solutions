#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long
#define ull unsigned long long

const int MOD = 998244353;

long long binpow(long long a, long long b, long long m) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve() {
    int a, b, l; cin >> a >> b >> l;
    int temp = l;
    set<int> k;
    do {
        k.insert(temp);
        int temp2 = temp;
        while(temp2 % b == 0) {
            temp2 /= b;
            k.insert(temp2);
        }
        if(temp % a == 0) {
            temp /= a;
        } else {
            temp = 0;
        }
    } while(temp > 0);
    cout << k.size() << endl;
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