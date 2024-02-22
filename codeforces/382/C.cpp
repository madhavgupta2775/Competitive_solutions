#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long
#define ull unsigned long long

const int MOD = 1e9 + 7;

class ReaderWriter 
{
private: 
    mutex m;
    condition_variable cv;
    atomic <int> count;
public: 
    void write() {
        unique_lock ul(m);
        while(count > 0) {
            cv.wait(ul);
        }
        count = -1;
        //write
        count = 0; ul.unlock(); cv.notify_all();
    }
    void read() {
        unique_lock ul(m);
        while(count < 0) {
            cv.wait(ul);
        }
        count++;
        ul.unlock();
        //read
        count--;
        cv.notify_one();
    }
};

void print_set(set<int> &s) {
    cout << s.size() << endl;
    for(auto x : s) {
        cout << x << " ";
    }
    cout << endl;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n); forn(i, 0, n) cin >> a[i];
    if(n == 1) {
        cout << -1 << endl;
        return;
    }
    sort(a.begin(), a.end());
    vector<int> diff(n - 1);
    map<int, int> mp;
    set<int> ans;
    forn(i, 0, n - 1) {
        diff[i] = a[i + 1] - a[i];
        mp[diff[i]]++;
    }
    if(mp.size() == 1) {
        if(n == 2) {
            ans.insert(a[0] - diff[0]);
            ans.insert(a[n - 1] + diff[0]);
            if(diff[0] % 2 == 0) {
                ans.insert(a[0] + diff[0] / 2);
            }
            print_set(ans);

        }
        else {
            ans.insert(a[0] - diff[0]);
            ans.insert(a[n - 1] + diff[0]);
            print_set(ans);
        }
    }
    else if(mp.size() == 2) {
        auto x = mp.begin(), y = mp.begin(); y++;
        auto smol = *x, big = *y;
        if((smol.second != 1 && big.second != 1) || (smol.second < big.second) || (smol.first * 2 != big.first)) {
            cout << 0 << endl;
            return;
        }
        cout << 1 << endl;
        for(int i = 0; i < n - 1; i++) {
            if(diff[i] == big.first) {
                cout << a[i] + smol.first << endl;
                break;
            }
        }
    }
    else {
        cout << 0 << endl;
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