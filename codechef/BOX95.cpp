#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long
#define ff first
#define ss second
#define pb push_back

// const int MOD2 = 1e9+7;
// const int MOD = 998244353;


int pow2(int x){
    int p = 1;
    while(p < x){
        p *= 2;
    }
    return p;
}


void solve() {
    int n, boxes = 1; cin >> n;
    multiset<int> a;
    forn(i, 0, n){
        int x; cin >> x;
        a.insert(x);
    }
    int curr = *a.rbegin();
    a.erase(a.find(curr));

    while(!a.empty()){
        int p = pow2(curr);
        auto it = a.lower_bound(p);
        auto limit = a.upper_bound(curr);
        if(limit == a.begin()){
            curr = *a.rbegin();
            a.erase(a.find(curr));
            boxes++;
            continue;
        }
        limit--;
        if(it == a.end()){
            curr = curr ^ (min(*limit, *a.rbegin()));
            a.erase(a.find(min(*limit, *a.rbegin())));
        }
        else if(it == a.begin()){
            curr = curr ^ *it;
            a.erase(it);
        }
        else{
            int x = *it;
            int y = *(--it);
            if(*limit < x){
                curr = curr ^ *limit;
                a.erase(a.find(*limit));
            }
            else if(curr ^ x > curr ^ y){
                curr = curr ^ x;
                a.erase(a.find(x));
            }
            else{
                curr = curr ^ y;
                a.erase(a.find(y));
            }
        }
    }
    cout << boxes << endl;

}   
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << setprecision(30);
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        solve(); 
    }
    return 0;
}