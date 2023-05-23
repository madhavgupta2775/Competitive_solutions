#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long
#define ff first
#define ss second

const int MOD2 = 1e9+7;
const int MOD = 998244353;

void solve() {
    int n, m, ans = 0; char temp;
    cin >> n >> m;
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    vector<vector<int>> v(n, vector<int>(m)), visited(n, vector<int> (m));
    queue<pair<int, int>> q;
     forn(i, 0, n){
        for(int j = 0; j < m; j++){
            cin >> temp;
            if(temp == '.'){
                v[i][j] = 1;
            }
            else{
                v[i][j] = 0;
            }
        }
    }
    forn(i, 0, n){
        for(int j = 0; j < m; j++){
            if(!visited[i][j] && v[i][j] == 1){
                ans++;
                visited[i][j] = 1;
                q.push({i, j});
                while(!q.empty()){
                    int x = q.front().first, y = q.front().second;
                    q.pop();
                    for(int k = 0; k < 4; k++){
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if(nx >= 0 && nx < n && ny >= 0 && ny < m && v[nx][ny] && visited[nx][ny] == 0){
                            q.push({nx, ny});
                            visited[nx][ny] = 1;
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
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