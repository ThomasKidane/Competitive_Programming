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

bool conts(vector<int>&v,int c){
    for(int i=0;i<v.size();i++){
        if(v[i]==c)return true;
    }
    return false;
}

void solve(){
    int n,m;
    cin>>n>>m;
    // cout<<"Here"<<endl;
    map<int,vector<int>> adj;
    map<int,vector<int>> revadj;
    forn(i,m){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        revadj[b].push_back(a);
    }
    int k;
    cin>>k;
    int a[k];
    forn(i,k){
        cin>>a[i];
    }
    vector<int> dist(n+1,(int)1e8);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    int s=a[0];
    int e=a[k-1];
    // from e to s;
    dist[e]=0;
    pq.push(make_pair(0,e));
    vector<bool> vis(n+1,false);
    // vis[e;
    while(!pq.empty()){
        int d=pq.top().ff;
        int v=pq.top().ss;
        pq.pop();
        if(!vis[v]){
            vis[v]=true;
            dist[v]=d;
            for(int i:revadj[v]){
                if(dist[i]>d+1){
                    pq.push(make_pair(d+1,i));
                }
            }
        }
    }
    // dbga(dist,n+1);
    int req=0;
    int extra=0;
    vector<bool> seen(n+1,false);
    for(int i=0;i<k-1;i++){
        map<int,int> vals;
        map<int,vector<int>> revval;
        int m=1e8;
        // seen[a[i]]=true;
        for(int j:adj[a[i]]){
            if(seen[j])continue;
            // seen[j]=true;
            vals[dist[j]]++;
            revval[dist[j]].push_back(j);
            if(m>dist[j])m=dist[j];
        }
        if(vals[m]==1){
            if(a[i+1]==revval[m].back()){
                req+=0;
            } else {
                req+=1;
            }
        } else {
            if(conts(revval[m],(a[i+1]))){
                extra+=1;
            } else {
                req+=1;
            }
        }
    }

    cout<<req<<' '<<req+extra<<endl;

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
