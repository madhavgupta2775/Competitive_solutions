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
    if(n < 3) {
        cout << 0 << endl;
    }
    else {
        cout << n-2 << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(30);
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        solve();
    }
    return 0;
}