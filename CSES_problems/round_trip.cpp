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

void findloop(int pp,int s,vector<int> &visited,vector<vector<int>> &adj,map<int,int> &seen){
    seen[s]=1;
    for(int e:adj[s]){
        if(seen[e]==1 && e!=pp){
            visited.push_back(e);
            return;
        } else if(e!=pp){
           visited.push_back(e);
           int p=visited.size();
           findloop(s,e,visited,adj,seen);
           if(visited.size()>p)return;
           else {
            visited.pop_back();
           }
        }
    }
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
        adj[b].push_back(a);
        adj[a].push_back(b);
    }
    bool done=false;
    vector<int> visited;
    map<int,int> seen;
    forn(i,n){
        if(seen[i]!=1){
            visited.push_back(i);
            findloop(-1,i,visited,adj,seen);
            if(visited.size()>1){
                done=true;break;
            } else {
                visited.pop_back();
            }
        }
    }

    if(done){
        string out="";
        int c=0;
        int s=visited.back();
        out+=to_string(s+1)+' ';
        c++;
        visited.pop_back();
        while(visited.back()!=s){
            out+=to_string(visited.back()+1)+' ';
            visited.pop_back();
            c++;
        }
        out+=to_string(s+1)+' ';
        c++;
        cout<<c<<endl;
        cout<<out<<endl;
    } else {
        cout<<"IMPOSSIBLE";
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
