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

void turn_to_cycle(int i,vector<vector<int>> &adj,map<int,bool>& notdouble,vector<bool>& cycle){
    notdouble[i]=true;
    cycle[i]=true;
    for(auto e: adj[i]){
        if(!notdouble[e]){
            turn_to_cycle(e,adj,notdouble,cycle);
        }
    }
}
// Where I am now, list of adj, current path, visited, cycle
void dfs(int i,int j,vector<vector<int>> &adj,vector<bool>& visited,vector<bool>& cycle){
    
    visited[j]=true;
    // dbgv(j);
    for(auto e: adj[j]){
        if(visited[e] && e!=i){
            
            map<int,bool> notdouble;
            turn_to_cycle(e,adj,notdouble,cycle);
            return;
        } else {
            if(!visited[e]){
                dfs(j,e,adj,visited,cycle);
            }
            
        }
    }
}



void solve(){
    int n;
    cin>>n;
    ll x,y,r;
    vector<vector<ll>> vals;
    vector<vector<int>> adj(n);
    forn(i,n){
        cin>>x>>y>>r;
        for(int j=0;j<i;j++){
            if(((vals[j][0]-x)*(vals[j][0]-x) + (vals[j][1]-y)*(vals[j][1]-y))==(r+vals[j][2])*(r+vals[j][2])){
                // cout<<"Hapennd"<<endl;
                adj[j].push_back(i);
                adj[i].push_back(j);
            }
        }
        vals.push_back({x,y,r});
    }

    vector<bool> cycle(n,false);
    vector<bool> visited(n,false);
    
    // vector<int> path;
    forn(i,n){
        if(!visited[i]){
            
            dfs(-1,i,adj,visited,cycle);
        }
    }
    // dbga(cycle,4);

    // forn(j,n){
    //     forn(i,adj[j].size()){
    //         cout<<adj[j][i]<<' ';
    //     }
    //     cout<<endl;
    // }
    forn(i,n){
        if(!cycle[i]){
            cout<<"YES";
            return;
        }
    }

    cout<<"NO";

    
    
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
