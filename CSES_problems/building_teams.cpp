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

int colorthegraph(int s,vector<vector<int>> &adj,int color[],bool visited[]){
    visited[s]=true;
    bool cant=false;
    for(int e:adj[s]){
        if(visited[e]){
            if(color[e]==color[s]){
                cant=true;
            }
        } else {
            color[e]=(color[s] ? 0 : 1);
            cant|=colorthegraph(e,adj,color,visited);
        }
    }

    if(cant)return 1;
    else return 0;
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n,vector<int> ());
    forn(i,m){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int color[n];
    bool visited[n]={false};
    color[0]=0;
    bool cant=false;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            color[i]=0;
            cant|=colorthegraph(i,adj,color,visited);
        }
    }
    if(cant){
        cout<<"IMPOSSIBLE";
    } else {
        forn(i,n){
            cout<<color[i]+1<<' ';
        }
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
