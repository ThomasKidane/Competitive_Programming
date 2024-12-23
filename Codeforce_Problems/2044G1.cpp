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

void makecycle(int s,int e,vector<bool>&vs,vector<bool>&cycle,map<int,int>&adj){
    cycle[e]=true;
    vs[e]=true;
    // cout<<"From cyle"<<endl;
    // dbgv(s);
    if(cycle[adj[e]]){
        return;
    } else {
        makecycle(s,adj[e],vs,cycle,adj);
    }
}

pair<bool,int> ispartcycle(int s,int e,vector<bool>&vs,vector<bool>&cycle,map<int,int>&adj,set<int>&all){
    vs[e]=true;
    all.insert(e);
    if(vs[adj[e]] && !cycle[adj[e]] && all.find(adj[e])!=all.end()){
        // cycle[adj[e]]=true;
        return make_pair(true,adj[e]);
    } else if(cycle[adj[e]] || vs[adj[e]]){
        return make_pair(false,0);
    } else {
        return ispartcycle(e,adj[e],vs,cycle,adj,all);
    }
}

int maxl(int s,int e,vector<bool>&vs,vector<bool>&cycle,map<int,vector<int>>&adj){
    int m=0;
    vs[e]=true;
    for(int i:adj[e]){
        // dbgv(i);
        // dbgv(s);
        // dbga(cycle,5);
        // dbgv(!cycle[])
        if(i!=s && !cycle[i]){
            // cout<<"hjh"<<endl;
            m=max(1+maxl(e,i,vs,cycle,adj),m);
        }
    }
    return m;
}

void solve(){
    int n;
    cin>>n;
    map<int,int> adj;
    map<int,vector<int>> revadj;
    // dbgv(n);
    forn(i,n){
        int d;
        cin>>d;
        d--;
        adj[i]=d;
        revadj[d].push_back(i);
    }
    vector<bool> vs(n,false);
    vector<bool> cycle(n,false);
    set<int> all;

    for(int i=0;i<n;i++){
        if(!vs[i]){
            all.clear();
            pair<bool,int> res=ispartcycle(0,i,vs,cycle,adj,all);
            // dbgv(i);
            // dbgv(res.ff);
            // dbgv(res.ss);
            // dbga(cycle,n);
            if(res.ff){
                makecycle(res.ss,res.ss,vs,cycle,adj);
            }
            // dbga(cycle,n);
        }
    }
    vector<bool> revvis(n,false);
    
    int m=0;
    for(int i=0;i<n;i++){
        if(cycle[i]){
            // cout<<"Here"<<endl;
            m=max(maxl(-1,i,revvis,cycle,revadj),m);
        }
    }

    cout<<m+2<<endl;
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
