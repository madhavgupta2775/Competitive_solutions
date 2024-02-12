#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

const int MOD = 998244353;

void solve() {
    vector<int> good;
    string s; cin >> s;
    for(auto x: s) good.push_back(x - 'a');
    sort(good.begin(), good.end());
    string temp; cin >> temp;
    int t; cin >> t; 
    for(int tt = 0; tt < t; tt++) {
        string q; cin >> q;
        int lp = 0, rp = q.size() - 1, li = 0, ri = temp.size()-1;
        while(temp[li] == q[lp] || (temp[li] == '?' && binary_search(good.begin(), good.end(), (int)q[lp] - 'a'))) {
            li++; lp++;
            if(li > ri || lp > rp) break;
        }
        if(rp >= lp && ri >= li) {
            while(temp[ri] == q[rp] || (temp[ri] == '?' && binary_search(good.begin(), good.end(), (int)q[rp] - 'a'))) {
                ri--; rp--;
                if(ri < li || rp < lp) break;
            }
        }
        if(li > ri && rp < lp) {
            cout << "YES" << endl;
        }
        else if(li == ri && temp[li] == '*') {
            if(rp < lp) cout << "YES" << endl;
            else {
                while(rp >= lp) {
                    if(!binary_search(good.begin(), good.end(), (int)q[lp] - 'a')) lp++;
                    else {
                        break;
                    }
                }
                if(rp < lp) cout << "YES" << endl;
                else cout << "NO" << endl;
            }
        }
        else {
            cout << "NO" << endl;
        }
    }
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
