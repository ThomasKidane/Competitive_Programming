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

struct Comp {
    bool operator()(const pair<ll,ll> &p1,const pair<ll,ll>& p2){
        return p1.ff>p2.ff;
    }
};

void solve(){
    ll n,m;
    cin>>n>>m;
    map<int,vector<pair<int,ll>>> adj;
    forn(i,m){
        int a,b;
        ll c;

        cin>>a>>b>>c;
        a--;
        b--;
        adj[a].push_back(make_pair(b,c));
        // adj[b].push_back(make_pair(a,c));
    }

    vector<bool> vis(n,false);
    vector<ll> dist(n,LLONG_MAX);
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,Comp> pq;
    dist[0]=0;
    pq.push(make_pair(0,0));
    while(!pq.empty()){
        ll d=pq.top().ff;
        ll u=pq.top().ss;
        pq.pop();
        if(!vis[u]){
            vis[u]=true;
            for(auto pp:adj[u]){
                if(dist[pp.ff]>dist[u]+pp.ss){
                    dist[pp.ff]=dist[u]+pp.ss;
                    pq.push(make_pair(dist[pp.ff],pp.ff));
                }
            }
        }
    }

    // dbga(dist,n);
    forn(i,n){
        cout<<dist[i]<<' ';
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
