#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
    bool r = false, w = true; string inp[8];
    for(int i = 0; i < 8; i++){
        int t = 0; cin >> inp[i];
        for(int j = 0; j < 8; j++){
            if(inp[i][j] == '#'){
                t++;
            }
            if(t == 2){
                r = true;
            }
            if(t == 1 && r && find(inp[i].begin() + j +1, inp[i].end(), '#') == inp[i].end() && w){
                cout << i +1 << " " << j +1 << endl; w = false;
            }
        }
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    for(int i = 0; i < t; i++){
        solve();
    }   
    return 0;
}