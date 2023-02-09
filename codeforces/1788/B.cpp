#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long
#define ff first
#define ss second

const int MOD2 = 1e9+7;
const int MOD = 998244353;
void dsum(int n, vector<int> &dig){
    int temp = 0;
    while(n > 0){
        temp = n%10; n /= 10;
        dig.push_back(temp);
    }
}

void solve() {
    int n, a = 0, b = 0, sa = 0, sb = 0, j = 0; cin >> n;
    vector<int> dia, dib(9);
    dsum(n, dia);
    a = n;
    forn(i, 0, dia.size()){
        sa += dia[i];
    }
    while(abs(sa - sb) >1){
        if(sa > sb){
            if(dia[j] != 0){
                dib[j]++; dia[j]--; sa--; sb++; a -= pow(10, j); b += pow(10, j);
            }
            else{
                j++;
            }
        }
    }
    cout << a << " " << b << endl;
}   
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        solve(); 
    }
    //solve();
    return 0;
}