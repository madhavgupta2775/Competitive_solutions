#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long
#define ff first
#define ss second
#define pb push_back

// const int MOD2 = 1e9+7;
// const int MOD = 998244353;

// make a funciton to convert a number to binary and then store it in a vector size 60
void convert(int x, vector<int> &v){
    int i = 0;
    while(x > 0){
        v[i] = x%2;
        x /= 2;
        i++;
    }
}


void solve() {
    int n, x, temp, aa = 0, bb = 0, cc = 0; cin >> n >> x;
    vector<vector<int>> a(n, vector<int>(60)), b(n, vector<int>(60)), c(n, vector<int>(60));
    vector<int> binaryofx(60), ans(60);
    bool flaga = false, flagb = false, flagc = false;
    convert(x, binaryofx);
    forn(i, 0, n){
        cin >> temp;
        convert(temp, a[i]);
    }
    forn(i, 0, n){
        cin >> temp;
        convert(temp, b[i]);
    }
    forn(i, 0, n){
        cin >> temp;
        convert(temp, c[i]);
    }
    while(binaryofx != ans){
        if(aa < n && flaga == false){
            forn(i, 0, 60){
                if(binaryofx[i] == 0 && a[aa][i] == 1){
                    flaga = true;
                    break;
                }
            }
            if(flaga == false){
                forn(i, 0, 60){
                    ans[i] = ans[i] | a[aa][i];
                }
                aa++;
            }
        }
        else if(bb < n && flagb == false){
            forn(i, 0, 60){
                if(binaryofx[i] == 0 && b[bb][i] == 1){
                    flagb = true;
                    break;
                }
            }
            if(flagb == false){
                forn(i, 0, 60){
                    ans[i] = ans[i] | b[bb][i];
                }
                bb++;
            }
        }
        else if(cc < n && flagc == false){
            forn(i, 0, 60){
                if(binaryofx[i] == 0 && c[cc][i] == 1){
                    flagc = true;
                    break;
                }
            }
            if(flagc == false){
                forn(i, 0, 60){
                    ans[i] = ans[i] | c[cc][i];
                }
                cc++;
            }
        }
        else{
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}   
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << setprecision(30);
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        solve(); 
    }
    return 0;
}