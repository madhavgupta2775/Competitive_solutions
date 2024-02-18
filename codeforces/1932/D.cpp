#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long
#define ull unsigned long long

const int MOD = 998244353;

void solve() {
    int n; cin >> n;
    char trum; cin >> trum;
    int trump;
    if(trum == 'C') trump = 0;
    else if(trum == 'D') trump = 1;
    else if(trum == 'H') trump = 2;
    else if(trum == 'S') trump = 3;
    vector<int> count(4);
    map<int, char> mp; mp[0] = 'C'; mp[1] = 'D'; mp[2] = 'H'; mp[3] = 'S';
    vector<vector<int>> cards(4);
    forn(i, 0, 2*n) {
        string temp; cin >> temp;
        if(temp[1] == 'C') {
            count[0]++; cards[0].push_back(temp[0] - '0');
        }
        else if(temp[1] == 'D') {
            count[1]++; cards[1].push_back(temp[0] - '0');
        }
        else if(temp[1] == 'H') {
            count[2]++; cards[2].push_back(temp[0] - '0');
        }
        else if(temp[1] == 'S') {
            count[3]++; cards[3].push_back(temp[0] - '0');
        }
    }
    int temp = (count[0] % 2) + (count[1] % 2) + (count[2] % 2) + (count[3] % 2);
    temp -= (count[trump] % 2); if(temp < 0) temp += 1;
    if(temp > count[trump] || (count[trump] - temp) % 2) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    forn(i, 0, 4) {
        sort(cards[i].begin(), cards[i].end());
    }
    int index = 0;
    forn(i, 0, 4) {
        if(i == trump) continue;
        for(int j = 0; j < cards[i].size(); j+=2) {
            if(j < cards[i].size() - 1) {
                string one = to_string(cards[i][j]); one += mp[i];
                string two = to_string(cards[i][j + 1]); two += mp[i];
                cout << one << " " << two << endl;
            }
            else {
                string one = to_string(cards[i][j]); one += mp[i];
                string two = to_string(cards[trump][index++]); two += mp[trump];
                cout << one << " " << two << endl;
            }
        }
    }
    for(int i = index; i < cards[trump].size(); i+=2) {
        if(i < cards[trump].size() - 1) {
            string one = to_string(cards[trump][i]); one += mp[trump];
            string two = to_string(cards[trump][i + 1]); two += mp[trump];
            cout << one << " " << two << endl;
        }
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