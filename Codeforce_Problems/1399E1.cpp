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

int dfs(int n,int p,vector<ll>&res, vector<vector<pair<int,ll>>>& adj,ll& S){
    // cout<<"here"<<endl;
    // cout<<
    // dbgv(adj[n].size());
    // if(adj[n].size()==1){
    //     return 1;
    // }
    int c=0;
    


    for(auto e:adj[n]){
        if(e.ff!=p){
            ll w=e.ss;
            int m=dfs(e.ff,n,res,adj,S);
            c+=m;
            // dbgv(m);
            // dbgv(w*m);
            S+=w*m;
            // cout<<"here"<<endl
            while(w>0){
                // w=(w+1)/2;
                
                res.push_back((w+1)/2*m);
                w/=2;
                
            }
        }
    }

    return max(c,1);
}

void solve(){
    ll n,s;
    cin>>n>>s;
    vector<vector<pair<int,ll>>> adj(n+1,vector<pair<int,ll>> ());
    forn(i,n-1){
        int u,v;
        ll w;
        cin>>u>>v>>w;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    ll Sum=0;
    vector<ll> res;
    int c=0;
    dfs(1,-1,res,adj,Sum);
    sort(res.begin(),res.end());
    // reverse(res.begin(),res.end());
    // dbgv(Sum);
    // dbga(res,res.size());

    while(Sum>s){
        c++;
        Sum-=res.back();
        res.pop_back();
    }
    
    cout<<c<<endl;
    
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
