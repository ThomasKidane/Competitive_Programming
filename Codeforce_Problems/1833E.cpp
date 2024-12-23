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

bool dfs(int e,int c,map<int,set<int>>&adj,bool visited[],set<int>&cur){
    visited[c]=true;
    bool res=false;
    cur.insert(c);
    for(int i:adj[c]){
        if(cur.find(i)!=cur.end() && i!=e){
            return true;
        } else {
            if(i!=e){
                res|=dfs(c,i,adj,visited,cur);
            }
        }
    }
    return res;
}

void solve(){
    int n;
    cin>>n;
    map<int,set<int>> adj;
    forn(i,n){
        int d;
        cin>>d;
        adj[i+1].insert(d);
        adj[d].insert(i+1);
    }
    bool visited[n+1]={false};
    visited[0]=true;
    int dis=0;
    int cycle=0;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            set<int> cur;
            bool res=dfs(0,i,adj,visited,cur);
            if(!res){
                dis++;
            } else {
                cycle++;
            }
        }
    }

    if(dis!=0){
        cout<<cycle+1<<' '<<cycle+dis<<endl;
    } else {
        cout<<cycle<<' '<<cycle<<endl;
    }
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
