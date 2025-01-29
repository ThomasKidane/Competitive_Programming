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

void dfs(int n,int p,ll h,ll&S,vector<pair<ll,ll>>&nodes,vector<vector<int>>&adj){
    // dbgv(n);
    // dbgv(S);
    // dbgv(h);
    int delta=0;
    if(nodes[n].ff>h){
        // S+=(nodes[n].ff-h);
        delta=(nodes[n].ff-h);
        h=nodes[n].ff;        
    } else if(nodes[n].ss<h){
        // if(adj[n].size()>2){
        //     // dbgv(h);
        //     // dbgv(nodes[n].ss);
        //     S+=(h-nodes[n].ss)/2;
        // }
        h=nodes[n].ss;
    }
    vector<ll> vals;

    ll amount=0;
    for(auto e:adj[n]){
        if(e!=p){
            vals.push_back(dfs(e,n,h,S,nodes,adj));
        }
    }
    sort(vals.begin(),vals.end());
    reverse(vals.begin(),vals.end());
    if(vals.size()>1){

    }
    // dbgv(delta);
    S+=delta;
    S+=amount;

    // return amount;
}

void solve(){
    int n;
    cin>>n;
    vector<pair<ll,ll>> nodes;
    int root=0;
    ll m=0;
    forn(i,n){
        ll l,r;
        cin>>l>>r;
        nodes.push_back(make_pair(l,r));
        if(l>m){
            root=i;
            m=l;
        }    
    }
    vector<vector<int>> adj(n);
    forn(i,n-1){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    // dbgv(m);
    ll S=m;
    dfs(root,-1,m,S,nodes,adj);

    cout<<S<<endl;
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
