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

int dfs(int p,int c,bool vs[],int res[],map<int,vector<int>>&adj){
    int h=0;
    for(int n:adj[c]){
        if(p!=c){
            if(!vs[n]){
                vs[n]=true;
                res[n]=dfs(c,n,vs,res,adj);
                h=max(1+res[n],h);
            } else {
                h=max(1+res[n],h);
            }
        }
    }

    vs[c]=true;
    res[c]=h;
    return h;
}

void solve(){
    int n,m;
    cin>>n>>m;
    int dp[n]={0};
    map<int,vector<int>> adj;
    forn(i,m){
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        adj[x].push_back(y);
        // adj[y].push_back(x);
    }
    bool vs[n]={false};
    int res[n];
    memset(res,0,sizeof(res));
    int mm=0;
    forn(i,n){
        if(!vs[i]){
            mm=max(dfs(-1,i,vs,res,adj),mm);
        }
    }

    cout<<mm<<endl;
}   

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
