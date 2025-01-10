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

void dfs(int e,int c,map<int,vector<int>>& adj,int dp[]){
    dp[c]=e+1;
    for(int i:adj[c]){
        if(i!=e){
            dfs(c,i,adj,dp);
        }
    }
}

void solve(){
    int n;
    cin>>n;
    map<int,vector<int>>adj;
    forn(i,n-1){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int dp[n];
    dp[0]=0; 
    dfs(-1,0,adj,dp);
    forn(i,n-1){
        cout<<dp[i+1]<<endl;
    }

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
