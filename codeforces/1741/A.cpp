#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long

const int MAXN = 200100;
const int MOD = 1000000007;
int cal(string a, int x){
    int re = 0;
    forn(i, 0, a.size()-1){
        re+= x;
    }
    return re;
}

void solve() {
    string a, b; cin >> a >> b;
    map <char, int> m; m['S'] = 1; 
    m['M'] = 2; m['L'] = 3;
    string::iterator ita = a.end() - 1, itb = b.end() - 1;
    if(*ita != *itb){
        if(m[*ita] > m[*itb]){ cout << '>' << endl;}
        else{ cout << '<' << endl;}
    }
    else{
        int x;
        if(*ita == 'S'){x = -1;}
        else if(*ita == 'M'){ cout << '=' << endl; return;}
        else{x = 1;}
        int ca = cal(a, x);
        int cb = cal(b, x);
        if(ca > cb){ cout << '>' << endl;}
        else if(ca < cb){ cout << '<' << endl;}
        else{ cout << '=' << endl;}
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        solve(); 
    }
    return 0;
}