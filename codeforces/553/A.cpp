#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long
#define ull unsigned long long

const int MOD = 1e9 + 7;

constexpr int P = 1000000007;
// assume -P <= x < 2P
int norm(int x) {
    if (x < 0) {
        x += P;
    }
    if (x >= P) {
        x -= P;
    }
    return x;
}
template<class T>
T power(T a, int b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}
struct Z {
    int x;
    Z(int x = 0) : x(norm(x)) {}
    // Z(ll x) : x(norm((int)(x % P))) {} //uncomment this line if there is no #define int long long
    int val() const {
        return x;
    }
    Z operator-() const {
        return Z(norm(P - x));
    }
    Z inv() const {
        assert(x != 0);
        return power(*this, P - 2);
    }
    Z &operator*=(const Z &rhs) {
        x = (int)x * rhs.x % P;
        return *this;
    }
    Z &operator+=(const Z &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    Z &operator-=(const Z &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    Z &operator/=(const Z &rhs) {
        return *this *= rhs.inv();
    }
    Z &operator%=(const Z &rhs) {
        x = x % rhs.x;
        return *this;
    }
    friend Z operator*(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res *= rhs;
        return res;
    }
    friend Z operator+(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res += rhs;
        return res;
    }
    friend Z operator-(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res -= rhs;
        return res;
    }
    friend Z operator/(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res /= rhs;
        return res;
    }
    friend Z operator%(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res %= rhs;
        return res;
    }
    friend bool operator==(const Z &lhs, const Z &rhs) {
        if(lhs.x == rhs.x) {
            return true;
        } else {
            return false;
        }
    }
    friend bool operator!=(const Z &lhs, const Z &rhs) {
        if(lhs.x != rhs.x) {
            return true;
        } else {
            return false;
        }
    }
    friend bool operator<(const Z &lhs, const Z &rhs) {
        if(lhs.x < rhs.x) {
            return true;
        } else {
            return false;
        }
    }
    friend bool operator>(const Z &lhs, const Z &rhs) {
        if(lhs.x > rhs.x) {
            return true;
        } else {
            return false;
        }
    }
    friend istream &operator>>(istream &is, Z &a) {
        int v;
        is >> v;
        a = Z(v);
        return is;
    }
    friend ostream &operator<<(ostream &os, const Z &a) {
        return os << a.val();
    }

};

//Z ans;
// or
//Z fact[100005];
//u get the point ig, Z is a new datatype like int.
//if u do Z%2, be sure to change P to 1000000000.
// CHANGE P and NN whenever required!!!!
//===========================================================
const int NN = 200005; //2e5
Z fac[NN];

Z NcR(int n, int r) {
    if(n<r) {return 0;}
    if(r==0) {return 1;}

    //fill factorial array

    return fac[n]/(fac[r]*fac[n-r]);
}

// dont go for the factorial array method in this question,
// since we may require a factorial of a very big number. Do this instead:
Z NcR_slow(int n, int r) {
    if(n < r) {return 0;}
    Z prod = 1;
    for(int i = 0; i < r; i++) {
        prod *= (n-i);
        prod /= (i+1);
    }
    return prod;
}

    //put this in int main
    // fac[0] = 1; fac[1] = 1; fac[2] = 2;
    // for(int i = 3; i < NN; i++) {
    //     fac[i] = fac[i-1]*i;
    // }
//===========================================================
//===============================================================================

namespace internal_choose {
std::vector<Z> factorial = {1}, inv_factorial = {1};
int built_max = 0;

void prepare_factorials(int max) {
  if (max <= built_max) return;
  max += max / 100;
  factorial.resize(max + 1);
  inv_factorial.resize(max + 1);
  for (int i = built_max + 1; i <= max; i++)
    factorial[i] = i * factorial[i - 1];
  inv_factorial[max] = factorial[max].inv();
  for (int i = max - 1; i > built_max; i--)
    inv_factorial[i] = inv_factorial[i + 1] * (i + 1);
  built_max = max;
}
};  // namespace internal_choose

Z factorial(int n) {
  if (n < 0) return 0;
  internal_choose::prepare_factorials(n);
  return internal_choose::factorial[n];
}

Z inv_factorial(int n) {
  if (n < 0) return 0;
  internal_choose::prepare_factorials(n);
  return internal_choose::inv_factorial[n];
}

Z choose(int n, int r) {
  if (r < 0 || r > n) return 0;
  internal_choose::prepare_factorials(n);
  return internal_choose::factorial[n] * internal_choose::inv_factorial[n - r] *
         internal_choose::inv_factorial[r];
}

Z permute(int n, int r) {
  if (r < 0 || r > n) return 0;
  internal_choose::prepare_factorials(n);
  return internal_choose::factorial[n] * internal_choose::inv_factorial[n - r];
}

Z inv_choose(int n, int r) {
  assert(r >= 0 && r <= n);
  internal_choose::prepare_factorials(n);
  return internal_choose::inv_factorial[n] * internal_choose::factorial[n - r] *
         internal_choose::factorial[r];
}

Z inv_permute(int n, int r) {
  assert(r >= 0 && r <= n);
  internal_choose::prepare_factorials(n);
  return internal_choose::inv_factorial[n] * internal_choose::factorial[n - r];
}

void solve() {
    int k, n = 0; cin >> k;
    vector<int> c(k); 
    forn(i, 0, k) {
        cin >> c[i];
        n += c[i];
    }
    Z ans = 1; int places = n;
    for(int j = k-1; j >= 0; j--) {
        ans *= choose(places-1, c[j]-1);
        places -= c[j];
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(30);
    int T = 1;
    // cin >> T;
    for(int I = 1; I <= T; I++) {
        solve();
    }
    return 0;
}