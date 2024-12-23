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

bool isBipartite(int V, vector<int> &color,map<int,vector<int>> &adj,vector<bool> &skip) {

    // Vector to store colors of vertices.
    // Initialize all as -1 (uncolored)
    
    // Queue for BFS
    queue<int> q;
    // cout<<"Here"<<endl;
    // Iterate through all vertices to handle disconnected graphs
    for(int i = 1; i <= V; i++) {
        // cout<<"But"<<endl;
        // dbgv(i);
        // dbgv(color[i]);
        // dbgv(skip[i]);
        // If the vertex is uncolored, start BFS from it
        if(color[i] == -1 && skip[i]) {

            // Assign first color (0) to the starting vertex
            color[i] = 0;
            q.push(i);
            // cout<<"read";
            
            // Perform BFS
            while(!q.empty()) {
                int u = q.front();
                q.pop();
                
                // Traverse all adjacent vertices
                for(auto &v : adj[u]) {

                    // If the adjacent vertex is uncolored,
                    // assign alternate color
                    if(color[v] == -1) {
                        color[v] = 1 - color[u];
                        q.push(v);
                    }

                    // If the adjacent vertex has the same color,
                    // graph is not bipartite
                    else if(color[v] == color[u]) {
                        return false;
                    }
                }
            }
        }
    }
    
    // If no conflicts in coloring, graph is bipartite
    return true;
}
// 0,1
pair<int,int> val01(int i,int e,map<int,vector<int>>&adj1,map<int,vector<int>>&adj2,vector<bool> &visited,vector<int>& node_color){
    int z=0;
    int o=0;
    visited[e]=true;
    if(node_color[i]==0){
        z++;        
    } else if (node_color[i]==1){
        // cout<<"Hey I am one "<<e<<endl;
        o++;
    }
    for(auto i:adj1[e]){
        if(!visited[i]){
            pair<int,int> res=val01(e,i,adj1,adj2,visited,node_color);
            z+=res.ff;
            o+=res.ss;
        }
    }
    for(auto i:adj2[e]){
        if(!visited[i]){
            pair<int,int> res=val01(e,i,adj1,adj2,visited,node_color);
            z+=res.ff;
            o+=res.ss;
        }
    }
    return make_pair(z,o);
}


void solve(){
    int n,m;
    cin>>n>>m;
    // map<int,vector<int>> adjs;
    vector<pair<int,int>> same;
    map<int,vector<int>> adjd;
    map<int,vector<int>> adjs;
    vector<bool> skip(n+1,false);
    forn(i,m){
        int a,b;
        cin>>a>>b;
        string s;
        cin>>s;
        if(s=="crewmate"){
            same.push_back(make_pair(a,b));
            adjs[a].push_back(b);
            adjs[b].push_back(a);
        } else {
            adjd[a].push_back(b);
            adjd[b].push_back(a);
            skip[a]=true;
            skip[b]=true;

        }
    }

        vector<int> node_color(n+1,-1);
        
        int d=0;
        // Make bipartie
        if(!isBipartite(n,node_color,adjd,skip)){
            cout<<-1<<endl;
            return;
        } else {
            dbga(node_color,n+1);
            for(auto p:same){
                if(node_color[p.ff]==-1 || node_color[p.ss]==-1){
                    // d+=node_color[p.ff]==-1;
                    // d+=node_color[p.ss]==-1;
                    if(node_color[p.ff]==-1){
                        node_color[p.ff]=node_color[p.ss];
                    } else {
                       node_color[p.ss]=node_color[p.ff]; 
                    }
                } else {
                    if(node_color[p.ff]!=node_color[p.ss]){
                        cout<<-1<<endl;
                        return;
                    // } else {
                    // }
                }
                }
        }}
        // int z=0;
        int mm=0;
        dbga(node_color,n+1);
        vector<bool> v(n+1,false);
        for(int i=1;i<=n;i++){
            if(!v[i] && node_color[i]!=-1){
                // cout<<"Her"<<endl;
                pair<int,int> res=val01(-1,i,adjd,adjs,v,node_color);
                mm+=max(res.ff,res.ss);
                cout<<"Res "<<res.ff<<' '<<res.ss<<endl;
            }
        }
        for(int i=1;i<=n;i++){
            if(node_color[i]==-1){d++;}
            // else if(node_color[i]==0){
            //     z++;
            // } else {
            //     o++;
            // }
        }
        // dbgv(o);
        // dbgv(z);
        dbgv(d);
        dbga(node_color,n+1);

        cout<<mm+d<<endl;

        }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
