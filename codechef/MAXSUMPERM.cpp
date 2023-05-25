#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long
#define ff first
#define ss second

const int MOD2 = 1e9+7;
const int MOD = 998244353;

void add(vector<int> &v, int N, int lo, int hi)
{
    v[lo] += 1;
    if (hi != N - 1)
       v[hi + 1] -= 1;
}
 
//  Utility method to get actual vay from operation vay
void updatearray(vector<int> &v, int N)
{
    //  convert vay into prefix sum vay
    for (int i = 1; i < N; i++)
        v[i] += v[i - 1];
}

void solve() {
    int n, q, a, b, sum = 0; cin >> n >> q;
    vector<int> v(n), count(n), ans(n);
    vector<pair<int, int>> uc(n);
    forn(i, 0, n){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    forn(i, 0, q){
        cin >> a >> b;
        add(count, n, a-1, b-1);
    }
    updatearray(count, n);
    forn(i, 0, n){
        uc[i].first = count[i];
        uc[i].second = i;
    }
    sort(uc.begin(), uc.end());
    forn(i, 0, n){
        ans[uc[i].second] = v[i];
        sum += ans[uc[i].second]*uc[i].first;
    }
    cout << sum << endl;
    forn(i, 0, n){
        cout << ans[i] << " ";
    }
    cout << endl;
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