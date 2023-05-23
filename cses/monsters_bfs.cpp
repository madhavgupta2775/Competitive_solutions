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
    int n, m, k = 0; char temp;
    cin >> n >> m;
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    string path;
    vector<vector<int>> v(n, vector<int>(m)), visited(n, vector<int> (m));
    vector<vector<int>> distance(n, vector<int>(m, INT_MAX)), distance_for_me(n, vector<int> (m));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>> (m));
    queue<pair<int, int>> q;
    pair<int, int> me;
    forn(i, 0, n){
        for(int j = 0; j < m; j++){
            cin >> temp;
            if(temp == 'A'){
                me = {i, j};
                v[i][j] = 1;
            }
            else if(temp == 'M'){
                q.push({i, j});
                v[i][j] = 1;
                distance[i][j] = 0;
            }
            else if(temp == '.'){
                v[i][j] = 1;
            }
            else{
                v[i][j] = 0;
            }
        }
    }
    vector<vector<int>> visited_by_me(n, vector<int> (m));
    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        q.pop();
        forn(k,0,4){
            int nx=x+dx[k];
            int ny=y+dy[k];
            if(nx>=0 && nx<n && ny>=0 && ny<m && v[nx][ny] && !visited[nx][ny]){
                visited[nx][ny]=1;
                distance[nx][ny] = min(distance[nx][ny], distance[x][y] + 1);
                q.push({nx,ny});
            }
        }
    }
    q.push(me);
    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        visited_by_me[x][y] = 1;
        q.pop();
        if(x == 0 || x == n-1 || y == 0 || y == m-1){
            pair<int, int> curr = {x, y};
            while(curr != me){
                int diffx = parent[curr.first][curr.second].first - curr.first;
                int diffy = parent[curr.first][curr.second].second - curr.second;
                if(diffx == dx[0]){
                    path = 'U' + path;
                }
                else if(diffx == dx[1]){
                    path = 'D' + path;
                }
                else if(diffy == dy[2]){
                    path = 'L' + path;
                }
                else{
                    path = 'R' + path;
                }
                curr = parent[curr.first][curr.second];
            }
            cout << "YES" << endl;
            cout << path.size() << endl;
            cout << path << endl;
            return;
        }
        forn(k,0,4){
            int nx=x+dx[k];
            int ny=y+dy[k];
            if(nx>=0 && nx<n && ny>=0 && ny<m && v[nx][ny] && distance_for_me[x][y] + 1 < distance[nx][ny] && visited_by_me[nx][ny] == 0){
                q.push({nx,ny});
                visited_by_me[nx][ny] = 1;
                parent[nx][ny] = {x, y};
                distance_for_me[nx][ny] = distance_for_me[x][y] + 1;
            }
        }
    }
    cout << "NO" << endl;
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