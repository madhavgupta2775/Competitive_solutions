#include <bits/stdc++.h>
using namespace std;

using ll = long long; using ld = long double;
#define int long long
#define double long double
#define hi_this_is_Subham_Pan ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define vin(a) for(auto&XX:a)cin>>XX;//idk y but it restricts my thought process at times
#define vout(v) for (auto XX: v)cout<<XX<<' ';cout<<endl;
#define vvin(a) for(auto& b : a) {for(auto& x : b) cin>>x;}
#define vvout(a) for(auto& b: a) {for(auto& x : b) {cout<<x<<" ";}cout<<endl;}
#define meh {cout<<"NO"<<endl;return;}
#define yay {cout<<"YES"<<endl;return;}
#define IMmeh {cout<<"NO"<<endl;continue;}
#define IMyay {cout<<"YES"<<endl;continue;}
//=======================================================------------------------------------------------------
void print(int t) {cout << t;} 
void print(string t) {cout << t;}
void print(char t) {cout << t;}
void print(double t) {cout << t;}
template <class T, class V> void print(pair <T, V> p);
template <class T> void print(vector <T> v);
template <class T> void print(set <T> v);
template <class T, class V> void print(map <T, V> v);
template <class T> void print(multiset <T> v);
template <class T, class V> void print(pair <T, V> p) {cout << "{"; print(p.first); cout << ","; print(p.second); cout << "}";}
template <class T> void print(vector <T> v) {cout << "[ "; for (T i : v) {print(i); cout << " ";} cout << "]\n";}
template <class T> void print(set <T> v) {cout << "[ "; for (T i : v) {print(i); cout << " ";} cout << "]\n";}
template <class T> void print(multiset <T> v) {cout << "[ "; for (T i : v) {print(i); cout << " ";} cout << "]\n";}
template <class T, class V> void print(map <T, V> v) {cout << "[ "; for (auto i : v) {print(i); cout << " ";} cout << "]\n";}
//=======================================================------------------------------------------------------
// #define pow2(x) (1ll<<(x))
template <typename T, typename U> T cdiv(T x, U y) {assert(y!=0);return (x > 0 ? (x + y - 1) / y : x / y);}
template <typename T, typename U> T fdiv(T x, U y) {assert(y!=0);return (x > 0 ? x / y : (x - y + 1) / y);}
template <typename T> int sgn(T val) {return (T(0) < val) - (val < T(0));} //sgn(x) gives -1/0/1
//returns integer, only works if a is a guarantee perfect square
long long sqroot(long long a){long long b = (long long) sqrtl(a);if ((b + 1) * (b + 1) == a){b++;}return b;}
constexpr ll inf = 1E18;
//(raise(a,b) = a^b)
long long raise(long long a, long long b) {long long res = 1;for(int i = 0; i<b; i++) {if(inf/res < a) return 0;res *= a;}return res;}
//=======================================================----------------------------------
const int MAX = 200007; //2*10^5 + 7
// const int MOD = 1e9+7; //comment it out if u want to use the other MOD
// // const int MOD = 998244353;
// const double EPS=1E-6;
// const int MAXN = 10000010; //1e7+10
//----------------


//modular arithmetic for MOD type questions code below:



constexpr int P = 998244353;
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
T power(T a, ll b) {
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
        x = ll(x) * rhs.x % P;
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
        ll v;
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
//===========================================================
const int N = 100003;
vector<int> vis(N, 0);
vector<Z> dp_inv_within(N, 0);
vector<Z> dp_number_of_ones(N, 0);
vector<Z> dp_number_of_zeroes(N, 0);
int n;
vector<vector<int>> adj;
map<pair<int, int>, int> edge_wts;
// Z res = 0;
void dfs(int v) {
    vis[v] = 1;
    for(int i = adj[v].size()-1; i>=0; i--) {
        auto x = adj[v][i];
        if(vis[x] == 1) {

        } else {
            dfs(x);
        }


        // dp_inv_within[v] += dp_inv_within[x];
        // if(edge_wts[{v,x}] == 1) {
        //     dp_inv_within[v] += dp_number_of_zeroes[x];
        // }

        Z temp = dp_inv_within[x] + ((edge_wts[{v,x}] == 1) ? dp_number_of_zeroes[x] : 0);
        Z temp_ones = dp_number_of_ones[x] + ((edge_wts[{v,x}] == 1) ? 1 : 0);
        dp_inv_within[v] += temp + temp_ones*dp_number_of_zeroes[v];

        dp_number_of_ones[v] += temp_ones;
        dp_number_of_zeroes[v] += dp_number_of_zeroes[x] + ((edge_wts[{v,x}] == 0) ? 1 : 0);

        
    }
}


void solve() {

    
    cin>>n;
    adj.resize(n+1);
    for(int i = 1; i<=n; i++) {
        int sz = 0;
        cin>>sz;
        for(int j = 0; j < sz; j++) {
            int b, wt; cin>>b>>wt;
            edge_wts[make_pair(i, b)] = wt;
            adj[i].push_back(b);
        }
    }   
    
    // print(edge_wts);
    // print(adj);
    dfs(1);

    cout<<dp_inv_within[1]<<endl;

    // cout<<"===="<<endl;

}

/*ngu*/
int32_t main() {
    hi_this_is_Subham_Pan
    //cout<<fixed<<setprecision(20)<<x; //-> for printing a double 'x'.
    
    int TT=1;
    // cin>>TT; //comment out this line if only 1 test case is needed
    while(TT--) {
        solve();
    }
 
    return 0;
}
