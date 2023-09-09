#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long
#define ff first
#define ss second
#define pb push_back

// A utility function to get the middle
// index from corner indexes.
int getMid(int s, int e) {
    return s + (e - s)/2;
}
 
/* A recursive function to get the Xor of
values in given range of the array. The
following are parameters for this function.
    st --> Pointer to segment tree
    si --> Index of current node in the segment tree.
           Initially 0 is passed as root is always
           at index 0.
    ss & se --> Starting and ending indexes of
                the segment represented by current
                node, i.e., st[si]
    qs & qe --> Starting and ending indexes of
                query range */
int getXorUtil(int *st, int ss, int se, int qs,
               int qe, int si)
{
    // If segment of this node is a part of given
    // range, then return the Xor of the segment
    if (qs <= ss && qe >= se)
        return st[si];
 
    // If segment of this node is outside
    // the given range
    if (se < qs || ss > qe)
        return 0;
 
    // If a part of this segment overlaps
    // with the given range
    int mid = getMid(ss, se);
    return getXorUtil(st, ss, mid, qs, qe, 2*si+1) ^
        getXorUtil(st, mid+1, se, qs, qe, 2*si+2);
}
 
/* A recursive function to update the nodes
which have the given index in their range.
The following are parameters
    st, si, ss and se are same as getXorUtil()
    i --> index of the element to be updated.
          This index is    in input array.*/
void updateValueUtil(int *st, int ss, int se, int i,
                     int prev_val, int new_val, int si)
{
    // Base Case: If the input index lies outside
    // the range of this segment
    if (i < ss || i > se)
        return;
 
    // If the input index is in range of this node,
    // then update the value of the node and its children
    st[si] = (st[si]^prev_val)^new_val;
    if (se != ss)
    {
        int mid = getMid(ss, se);
        updateValueUtil(st, ss, mid, i, prev_val,
                        new_val, 2*si + 1);
        updateValueUtil(st, mid+1, se, i, prev_val,
                        new_val, 2*si + 2);
    }
}
 
// The function to update a value in input
// array and segment tree. It uses updateValueUtil()
// to update the value in segment tree
void updateValue(int arr[], int *st, int n,
                 int i, int new_val)
{
    // Check for erroneous input index
    if (i < 0 || i > n-1)
    {
        printf("Invalid Input");
        return;
    }
    int temp = arr[i];
    // Update the value in array
    arr[i] = new_val;
 
    // Update the values of nodes in segment tree
    updateValueUtil(st, 0, n-1, i, temp, new_val, 0);
}
 
// Return Xor of elements in range from index qs (query start)
// to qe (query end). It mainly uses getXorUtil()
int getXor(int *st, int n, int qs, int qe)
{
    // Check for erroneous input values
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Invalid Input");
        return 0;
    }
 
    return getXorUtil(st, 0, n-1, qs, qe, 0);
}
 
// A recursive function that constructs
// Segment Tree for array[ss..se]. si is
// index of current node in segment tree st
int constructSTUtil(int arr[], int ss, int se,
                    int *st, int si)
{
    // If there is one element in array,
    // store it in current node of segment
    // tree and return
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
 
    // If there are more than one elements,
    // then recur for left and right subtrees
    // and store the Xor of values in this node
    int mid = getMid(ss, se);
    st[si] = constructSTUtil(arr, ss, mid, st, si*2+1) ^
            constructSTUtil(arr, mid+1, se, st, si*2+2);
    return st[si];
}
 
/* Function to construct segment tree from given array.
This function allocates memory for segment tree and
calls constructSTUtil() to fill the allocated memory */
int *constructST(int arr[], int n)
{
    // Allocate memory for segment tree
 
    // Height of segment tree
    int x = (int)(ceil(log2(n)));
 
    // Maximum size of segment tree
    int max_size = 2*(int)pow(2, x) - 1;
 
    // Allocate memory
    int *st = new int[max_size];
 
    // Fill the allocated memory st
    constructSTUtil(arr, 0, n-1, st, 0);
 
    // Return the constructed segment tree
    return st;
}

void solve() {
    int n; cin >> n;
    int a[n];
    forn(i, 0, n) {
        cin >> a[i];
    }
    int *st = constructST(a, n);
    string s; cin >> s;
    int q; cin >> q;
    int xor0 = 0, xor1 = 0;
    forn(i, 0, n) {
        if(s[i] == '0') {
            xor0 ^= a[i];
        } else {
            xor1 ^= a[i];
        }
    }
    forn(i, 0, q) {
        int b; cin >> b;
        if(b == 1) {
            int start, end; cin >> start >> end;
            start--; end--;
            xor0 ^= getXor(st, n, start, end);
            xor1 ^= getXor(st, n, start, end);
        }
        else {
            int c; cin >> c;
            if(c == 0) {
                cout << xor0 << " ";
            } else {
                cout << xor1 << " ";
            }
        }
    }
    cout << endl;
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