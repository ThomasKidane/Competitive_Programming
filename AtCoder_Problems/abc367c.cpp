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

int Su(vector<int> cur){
    int res=0;
    forn(i,cur.size())res+=cur[i];
    return res;
}

void addV(int c,int n,int k,vector<int> &cur,vector<vector<int>> &vals,int r[]){
    if(c==1){
        for(int i=1;i<=r[n-1];i++){
            cur.push_back(i);
            if(Su(cur)%k==0)vals.push_back(cur);
            cur.pop_back();
        }
    }
    else {
        for(int i=1;i<=r[n-c];i++){
            cur.push_back(i);
            addV(c-1,n,k,cur,vals,r);
            cur.pop_back();
        }
    }   
}

void solve(){
    int n,k;
    cin>>n>>k;
    int r[n];
    forn(i,n)cin>>r[i];
    vector<vector<int>> vals;
    vector<int> cur;
    addV(n,n,k,cur,vals,r);
    sort(vals.begin(),vals.end());
    forn(i,vals.size()){
        forn(j,n){
            cout<<vals[i][j]<<' ';
        }
        cout<<endl;
    }
}

int main() {
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
