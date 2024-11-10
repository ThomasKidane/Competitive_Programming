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
void solve(){
    ll n,m,t,d;
    cin>>n>>m>>t>>d;// number of intersections, number of roads, number of repare stations, distance you can ride without failing

    vector<vector<ll>> distance(n+1); // current dis, current stamina
    vector<vector<ll>> adj(n+1); // destiantiona, required stamina
    bool repairS(n+1);
    forn(i,t){
        ll d;
        cin>>d;
        repairS[d]=true;
    }
    forn(i,m){
        ll a,b,s;
        cin>>a>>b>>s;
        adj[a].push_back({b,s});
        adj[b].push_back({a,s});
    }
    bool processed(n+1);

    priority_queue<vector<int>> q;


    for (ll i = 1; i <= n; i++) {distance[i] = vector<int>{INF,0};}

    distance[1][0] = 0;
    distance[1][1] = d;
    q.push(vector<int>{0,1,d}); // distance, destination, stamina
    while (!q.empty()) {
    ll dist=q.top()[0];
    ll a=q.top()[1];
    ll stim=q.top()[2];

    if (processed[a]) continue;
    processed[a] = true;
    for (auto u : adj[a]) {
        ll b = u[0] w = u[1]; // destination, required stamina
        if (dist+w < distance[b][0]  &&   stim>=w) {
            distance[b][0] = dist+w;
            distance[b][1] = stim-w;
            if(repairS[b]){
                distance[b][1]=d;
            }
            q.push(vector<int>{-(dist+w),b,distance[b][1]});
        }
    }
    }

    cout<<distance[n][0];


    
}

int main() {
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
