#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
map<int, int> m;
vector<vector<vector<double> > > t;

double Curse(int i, int j, int k, int l)
{
    double ans = 0;
    if (i == n)
    {
        return 0;
    }
    if (t[j][k][l] != -1){
        return t[j][k][l];
    }
    ans += (double)n / (n - i);
    if (j > 0)
    {
        ans += (j*Curse(i + 1, j - 1, k, l)) / (double)(n - i);
    }
    if (k > 0)
    {
        ans += (k*Curse(i, j + 1, k - 1, l)) / (double)(n - i);
    }
    if (l > 0)
    {
        ans += (l*Curse(i, j, k + 1, l - 1)) / (double)(n - i);
    }
    //cout << ans << " " << i << " " << j << " " << k << " " << l << endl;
    return t[j][k][l] = ans;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(15);
    cin >> n;
    v.resize(n);
    t.resize(n+1, vector<vector<double> > (n+1,vector<double> (n+1,-1)));
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        m[v[i]] += 1;
    }
    cout << Curse(0, m[1], m[2], m[3]) << endl;
    return 0;
}