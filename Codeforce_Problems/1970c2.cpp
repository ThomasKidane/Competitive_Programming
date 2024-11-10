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

int dfs(int p,vector<bool> visited,map<int,vector<int>> &edges){
    int r=0;
    forn(i,edges[p].size()){
        if(!visited[edges[p][i]]){
            visited[edges[p][i]]=true;
            r|=(1-dfs(edges[p][i],visited,edges));
        }
    }
    return r;
}

void solve(){
    int n,t;
    cin>>n>>t;
    map<int,vector<int>> edges;
    forn(i,n-1){
        int u,v;
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    vector<bool> visited(n+1);
    int s;
    cin>>s;
    visited[s]=true;
    if(dfs(s,visited,edges)){
        cout<<"Ron";
    } else {
        cout<<"Hermione";
    }
    // cout<<dfs(s,visited,edges)<<endl;
    
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
