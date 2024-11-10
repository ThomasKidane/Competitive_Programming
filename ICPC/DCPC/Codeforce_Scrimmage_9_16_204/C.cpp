#include<bits/stdc++.h>

using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

#define forn(i,n) for(int i=0;i<n;i++)
#define dbgv(v) cout<<#v<<" "<<v<<endl
#define dbga(a,n) forn(i,n-1) {cout<<a[i]<<' ';} cout<<a[n-1]<<'\n';

// int sum(int a, int b,int len) {
//     a += n; b += n;
//     int s = 0;
//     while (a <= b) {
//     if (a%2 == 1) s += tree[a++];
//     if (b%2 == 0) s += tree[b--];
//     a /= 2; b /= 2;
//     }
//     return s;
// }

// int fix(int k) {
//     int s = 0;
//     while (k >= 1) {
//     s += tree[k];
//     k -= k&-k;
//     }
//     return s;
// }

void adj(int k, int x,int len,vector<int> &tree) {
    k += len-2;
    int l=1;
    tree[k] = x;
    for (k /= 2; k >= 1; k /= 2) {
        if(l%2==1){
            tree[k] = (tree[2*k]|tree[2*k+1]);
        } else {
            tree[k] = (tree[2*k]^tree[2*k+1]);
        }
        l++;
    }
}


void build_segtree(vector<int>& arr, int start, int end, vector<int>& tree, int index,int l) {
    if (start == end) {
        tree[index] = arr[start];
        return;
    }

    int mid = (start + end) / 2;
    build_segtree(arr, start, mid, tree, 2 * index,l+1);
    build_segtree(arr, mid + 1, end, tree, 2 * index + 1,l+1);
    if(l%2==1){
        tree[index] = tree[2 * index + 1] | tree[2 * index + 2];
    } else {
        tree[index] = tree[2 * index + 1] ^ tree[2 * index + 2];
    }
    
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> tree((int)pow(2,n+1));
    vector<int> arr;
    forn(i,(int)pow(2,n)){
        int d;
        cin>>d;
        arr.push_back(d);
    }
    build_segtree(arr,0,pow(2,n)-1,tree,0,1 );
    // dbgv(n);
    cout<<"From"<<endl;
    dbga(tree,pow(2,n+1));
    if(n%2==1){
        // dbgv(tree[1]);
        cout<<(tree[1]|tree[2])<<endl;
    } else {
        // dbgv(tree[1]);
        // dbgv(tree[2]);
        cout<<(tree[1]^tree[2])<<endl;
    }
    forn(i,m){
        int ni,tv;
        cin>>ni>>tv;
        // pv=arr[ni-1];
        adj(ni,tv,pow(2,n),tree);
        dbga(tree,pow(2,n+1));
        if(n%2==1){
            cout<<(tree[1]|tree[2])<<endl;
        } else {
            cout<<(tree[1]^tree[2])<<endl;
        }
        // adj(ni,pv,pow(2,n),tree);
        // dbga(tree,pow(2,n+1));
    }

}


int main() {
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
