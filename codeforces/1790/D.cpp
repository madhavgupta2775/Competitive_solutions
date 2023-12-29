#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

void solve() {
    int n; cin >> n;

    map<int, int> frequency_map; // stores frequency of each element
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        frequency_map[x]++;
    }

    int answer = 0, previous_frequency = 0, current_frequency = 0; // current_frequency is the number of dolls being constructed at the moment
    for(auto x: frequency_map) {
        if(current_frequency == 0) {
            current_frequency = x.second;
        }
        else {
            if(x.first == previous_frequency + 1) { // some dolls will have the current number
                answer += max(0LL, current_frequency - x.second);
                current_frequency = x.second;
            }
            else { // new dolls will be constructed starting from this number
                answer += current_frequency;
                current_frequency = x.second;
            }
        }
        previous_frequency = x.first;
    }
    if(current_frequency != 0) {
        answer += current_frequency;
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