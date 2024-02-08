#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

const int MOD = 998244353;

vector<long long> segmentedSieve(long long L, long long R) {
    // generate all primes up to sqrt(R)
    long long lim = sqrt(R);
    vector<char> mark(lim + 1, false);
    vector<long long> primes;
    for (long long i = 2; i <= lim; ++i) {
        if (!mark[i]) {
            primes.emplace_back(i);
            for (long long j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }

    // vector<char> isPrime(R - L + 1, true);
    // for (long long i : primes)
    //     for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
    //         isPrime[j - L] = false;
    // if (L == 1)
    //     isPrime[0] = false;
    return primes;
}

vector<int> prime_squares;

void solve() {
    int n;
    cin >> n;
    if(binary_search(prime_squares.begin(), prime_squares.end(), n)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(30);
    int T = 1;
    cin >> T;
    vector<long long> primes = segmentedSieve(1, 1e12);
    for(int i = 0; i < primes.size(); i++) {
        prime_squares.push_back(primes[i] * primes[i]);
    }
    for(int I = 1; I <= T; I++) {
        solve();
    }
    return 0;
}
