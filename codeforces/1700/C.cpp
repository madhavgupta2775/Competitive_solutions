#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)    
#define endl "\n" 
#define int long long

const int MOD = 1e9 + 7;
const int noop = 0;

struct node
{
    int sum;
    int pref;
    int suff;
    int ans;
    node()
    {
        sum = pref = suff = ans = 0;
    }
    node(int val,int tl,int tr)
    {
        sum = val*(tr-tl+1);
        pref = suff = ans = max(0LL,sum);
    }
    node operator+(const node &a)
    {
        node res;
        res.sum = sum + a.sum;
        res.pref = max(pref, sum + a.pref);
        res.suff = max(a.suff, a.sum + suff);
        res.ans = max({ans, a.ans, suff + a.pref});
        return res;
    }
};

class Segtree
{
private:
    vector<int> v, pref, suff, sum;
    vector<int> lazy;
    int n;
public:
    Segtree(int n, vector<int> &a) : n{n}
    {
        v.resize(4 * n, identity());
        lazy.resize(4 * n, noop);
        build(a, 1, 0, n-1);
    }
    void build(vector<int> &a, int si, int ss, int se)
    {
        if (ss == se)
        {
            v[si] = a[ss];
            return;
        }
        int mid = (ss + se) / 2;
        build(a, 2 * si, ss, mid);
        build(a, 2 * si + 1, mid + 1, se);
        // pref[si] = max(pref[si*2], sum[si*2] + pref[si*2 + 1]);
        // suff[si] = max(suff[si*2 + 1], sum[si*2 + 1] + suff[si*2]);
        // sum[si] = sum[si*2] + sum[si * 2 + 1];
        // v[si] = op(si);
        v[si] = op(v[si*2], v[si*2 + 1]);
    }
    int op(int si) 
    {
        return max(0ll, max(v[si*2], max(v[si*2 + 1], suff[si*2] + pref[si*2 + 1])));
    }
    int op(int a, int b)
    {
        return a + b;  
    }
    vector<int> op(vector<int> a, vector<int> b)
    {
        vector<int> c(40, 0);
        for(int i = 0; i < 40; i++)
            c[i] = a[i] | b[i];
        return c;
    }
    int identity()
    {
        return 0;
    }
    // void update(int pos, int val, int si, int ss, int se)
    // {
    //     if(ss == se)
    //     {
    //         v[si] = val;
    //         return;
    //     }
    //     int mid = (ss + se) / 2;
    //     if(pos <= mid)
    //         update(pos, val, 2 * si, ss, mid);
    //     else
    //         update(pos, val, 2 * si + 1, mid + 1, se);
 
    //     v[si] = op(v[si*2], v[si*2 + 1]);
    // }
    void update(int val, int si, int ss, int se, int l, int r) 
    {
        if(l > se || r < ss)
            return;
        if(l <= ss && r >= se) {
            // v[si] = op(v[si], val);
            // lazy[si] = op(lazy[si], val);
            v[si] += val;
            lazy[si] += val;
            return;
        }
        push(si, ss, se);
        int mid = (ss + se) / 2;
        update(val, si*2, ss, mid, l, r);
        update(val, si*2 + 1, mid + 1, se, l, r);
        v[si] = op(v[si*2], v[si*2 + 1]);
    }
    void update(int val, int l, int r)
    {
        update(val, 1, 0, n-1, l, r);
    }
    // void update(int pos, int val) 
    // {
    //     update(pos, val, 1, 0, n-1);
    // }
    void push(int si, int ss, int se)
    {
        if(lazy[si] == noop)
            return;
        int mid = (ss + se) / 2;
        // v[si*2] = op(v[si*2], lazy[si]);
        // v[si*2 + 1] = op(v[si*2 + 1], lazy[si]);
        // lazy[si*2] = op(lazy[si*2], lazy[si]);
        // lazy[si*2 + 1] = op(lazy[si*2 + 1], lazy[si]);
        v[si*2] += lazy[si];
        lazy[si*2] += lazy[si];
        v[si*2 + 1] += lazy[si];
        lazy[si*2 + 1] += lazy[si];
        lazy[si] = noop;
    }
    // int query(int si, int ss, int se, int l, int r)
    // {
    //     if(l > se || r < ss) 
    //         return identity();
    //     if(l <= ss && r >= se) 
    //         return v[si];
    //     push(si, ss, se);
    //     return op(query(si*2, ss, (ss + se)/2, l, r), query(si*2+1, (ss + se)/2 + 1, se, l, r));
    // }
    // int query(int x, int si, int ss, int se) 
    // {   
    //     if(v[si] < x) 
    //         return -1;
 
    //     if(ss == se && v[si] == x) 
    //         return ss;
 
    //     int t = query(x, si*2, ss, (ss + se)/2);
    //     if(t != -1) 
    //         return t;
            
    //     return query(x - v[si*2], si*2 + 1, (ss + se)/2 + 1, se);
    // }
    int query()
    {
        return v[1];
    }
    int access(int pos, int si, int ss, int se)
    {
        if(ss == se)
            return v[si];
        push(si, ss, se);
        int mid = (ss + se) / 2;
        if(pos <= mid)
            return access(pos, 2 * si, ss, mid);
        else
            return access(pos, 2 * si + 1, mid + 1, se);
    }
    // int access(int pos, int si, int ss, int se)
    // {
    //     if(ss == se)
    //         return v[si];
    //     int mid = (ss + se) / 2;
    //     if(pos <= mid)
    //         return access(pos, 2 * si, ss, mid) + v[si];
    //     else
    //         return access(pos, 2 * si + 1, mid + 1, se) + v[si];
    // }
    int access(int pos)
    {
        return access(pos, 1, 0, n-1);
    }
    // void range_update(int si, int ss, int se, int l, int r, int val)
    // {
    //     if(l > se || r < ss) 
    //         return;
    //     if(l <= ss && r >= se)
    //     {
    //         v[si] += val;
    //         return;
    //     }
    //     int mid = (ss + se) / 2;
    //     range_update(si*2, ss, mid, l, r, val);
    //     range_update(si*2 + 1, mid + 1, se, l, r, val);
    // }
    // void traverse()
    // {
    //     for(auto i : v)
    //         cout << i << " ";
    //     cout << endl;
    // }
};

void solve() {
    int n; cin >> n;
    vector<int> a(n); 
    forn(i, 0, n) {
        cin >> a[i];
    }
    int ans = 0, min_val = a[0], sub = 0;
    forn(i, 0, n) {
        a[i] -= sub;
        int val = a[i];
        if(val <= min_val) {
            min_val = val;
            if(i > 0) {
                int diff = min_val - a[i - 1];
                if(diff < 0) {
                    ans += -1 * diff;
                }
            }
            if(i < n - 1) {
                int diff = min_val - a[i + 1] + sub;
                if(diff < 0) {
                    sub += -1 * diff;
                    ans += -1 * diff;
                }
            }
        }
        if(i == n-1) {
            ans += abs(min_val);
        }
    }
    cout << ans << endl;
}


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    // cout << setprecision(30);
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        solve();
    }
    return 0;
}
