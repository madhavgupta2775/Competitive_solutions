#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long
#define ff first
#define ss second

const int MOD2 = 1e9+7;
const int MOD = 998244353;
void sieve(int n, vector<bool> primes){
    vector<bool> temp(n, 1);
    forn(i, 2, n+1){
        if(primes[i]==0){
            continue;
        }
        for(int j = i; j <= n; j += i){
            primes[j] = 0;
        }
    }
    primes = temp;
}

void solve() {
    int n, ans = 0, ta = 0, tb = 0; cin >> n;
    string s; cin >> s;
    vector<int> a(26), b(26);
    forn(i, 0, n){
        b[s[i]-'a']++;
    }
    forn(i, 0, n){
        ta = 0; tb = 0;
        a[s[i]-'a']++;
        b[s[i]- 'a']--;
        forn(i, 0, 26){
            if(a[i]){
                ta++;
            }
            if(b[i]){
                tb++;
            }
        }
        ans = max(ans, ta+tb);
    }
    cout << ans << endl;
}   
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        solve(); 
    }
    //solve();
    return 0;
}