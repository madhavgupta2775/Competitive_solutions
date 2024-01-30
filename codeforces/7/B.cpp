#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

const int MOD = 1e9 + 7;

bool insert(int temp, multiset<pair<int, int>>&mem, int& index, vector<pair<int, int>>& vals, set<pair<int, int>>& ptrs) {
    for(auto x: mem) {
        if(x.second >= temp) {
            vals.push_back({x.first, x.first + temp});
            ptrs.insert({x.first, index+1});
            mem.erase(x);
            x.first += temp; x.second -= temp; index++;
            if(x.second > 0) mem.insert(x);
            return true;
        }
    }
    return false;
}

bool erase(int temp, multiset<pair<int, int>>& mem, int& index, vector<pair<int, int>>& vals, set<pair<int, int>>& ptrs) {
    temp--;
    if(temp >= index || temp < 0 || vals[temp].first == 1e9) return false;
    for(auto x: mem) {
        if(x.first == vals[temp].second ) {
            ptrs.erase({vals[temp].first, temp+1});
            mem.erase(x);
            x.first = vals[temp].first; x.second += vals[temp].second - vals[temp].first;
            mem.insert(x);
            vals[temp].first = vals[temp].second = 1e9;
            return true;
        }
        else if(x.second + x.first == vals[temp].first) {
            ptrs.erase({vals[temp].first, temp+1});
            mem.erase(x);
            x.second += vals[temp].second - vals[temp].first;
            mem.insert(x);
            vals[temp].first = vals[temp].second = 1e9;
            return true;
        }
    }
    mem.insert({vals[temp].first, vals[temp].second - vals[temp].first});
    ptrs.erase({vals[temp].first, temp+1});
    vals[temp].first = vals[temp].second = 1e9;
    return true;
}

void defragment(multiset<pair<int, int>>& mem, vector<pair<int, int>>& vals, set<pair<int, int>>& ptrs, int m) {
    int temp = 0;
    map<pair<int, int>, pair<int, int>> actions;
    for(auto x: ptrs) {
        vals[x.second-1].second += temp - vals[x.second-1].first;
        vals[x.second-1].first = temp;
        actions[x] = {temp, x.second};
        temp += vals[x.second-1].second - vals[x.second-1].first;
    }
    for(auto x: actions) {
        ptrs.erase(x.first);
        ptrs.insert({x.second.first, x.second.second});
    }
    mem.clear();
    mem.insert({temp, m - temp});
}

void solve() {
    int t, m; cin >> t >> m;
    string s;
    vector<pair<int, int>> vals;
    multiset<pair<int, int>> mem;
    set<pair<int, int>> ptrs;
    mem.insert({0, m});
    int temp = 0, index = 0;
    for(int i = 0; i < t; i++) {
        cin >> s;
        if(s == "alloc") {
            cin >> temp;
            if(insert(temp, mem, index, vals, ptrs)) {
                cout << index << endl;
            }
            else cout << "NULL" << endl;
        }
        else if(s == "erase") {
            cin >> temp;
            if(!erase(temp, mem, index, vals, ptrs)) {
                cout << "ILLEGAL_ERASE_ARGUMENT" << endl;
            }
        }
        else {
            defragment(mem, vals, ptrs, m);
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    // cout << setprecision(30);
    int T = 1;
    // cin >> T;
    for(int I = 1; I <= T; I++) {
        solve();
    }
    return 0;
}