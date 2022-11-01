#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int cpal(int h, int m){
    if((h/10) == (m%10) && (h%10) == (m/10)){
        return 1;
    }
    else{
        return 0;
    }
}
void solve(){
    string inp; 
    int h = 0, m = 0, x, n = 0, f, dh,dm; cin >> inp >> x; 
    string ih = inp.substr(0,2); string im = inp.substr(3,2);
    h = stoi(ih); m = stoi(im); dh = h; dm = m;
    do
    {
        n += cpal(h, m); int tp = x;
        h+= tp/60; tp %= 60;
        if(m+tp <60){
            m+=tp;
            if(h>23){
                h-=24;
            } 
        }
        else if(h >= 23){
            h -= 23;
            m+= tp-60;
        }
        else{
            h++; m+=tp-60;
        }
    }
    while(h != dh || m != dm);
    cout << n << endl;
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