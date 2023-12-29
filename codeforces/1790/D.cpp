#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

void solve() {
    int n; cin >> n;

    multiset<int> dolls;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        dolls.insert(x);
    }

    int answer = 0, previous_frequency = 0, current_frequency = 0, previous_element = 0;

    for(auto x: dolls) {
        if(x == previous_element) continue;

        current_frequency = dolls.count(x);
        if(current_frequency != 0) {
            if(x == previous_element + 1) {
                answer += max(0ll, previous_frequency - current_frequency);
            }
            else {
                answer += previous_frequency;
            }
        }

        previous_element = x;
        previous_frequency = current_frequency;
    }
    if(previous_frequency != 0) {
        answer += previous_frequency;
    }

    cout << answer << endl;
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