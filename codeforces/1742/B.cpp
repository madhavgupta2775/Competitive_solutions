#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
    int leng, a; vector <int> vec; bool pre = false;
    cin >> leng;
    for(int i = 0; i < leng; i++){
        cin >> a; 
        if(find(vec.begin(), vec.end(), a) != vec.end()){
            pre = true;
        }
        vec.push_back(a);
    }
    if(pre == true){
        cout << "NO\n";
    }
    else{
        cout << "YES\n";
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