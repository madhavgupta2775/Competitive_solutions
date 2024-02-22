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

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> rows(n), cols(n);
    forn(i, 0, n) {
        for(int j = 0; j < n; j++) {
            char c; cin >> c;
            if(c == '.') {
                if(rows[i].first == 0) {
                    rows[i].first = i + 1;
                    rows[i].second = j + 1;
                }
                if(cols[j].first == 0) {
                    cols[j].first = i + 1;
                    cols[j].second = j + 1;
                }
            }
        }
    }
    bool flag = true;
    forn(i, 0, n) {
        if(rows[i].first == 0) {
            flag = false;
            break;
        }
    }
    if(flag) {
        forn(i, 0, n) {
            cout << rows[i].first << " " << rows[i].second << endl;
        }
        return;
    }
    forn(i, 0, n) {
        if(cols[i].first == 0) {
            cout << -1 << endl;
            return;
        }
    }
    forn(i, 0, n) {
        cout << cols[i].first << " " << cols[i].second << endl;
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