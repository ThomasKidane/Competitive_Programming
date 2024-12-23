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

pair<int,int> farthestnode(int e,int c,map<int,vector<int>>&adj,int dist[],int d){
    int v=0;
    pair<int,int> res={c,0};
    for(int i:adj[c]){
        if(i!=e){
            pair<int,int> val=farthestnode(c,i,adj,dist,d+1);
            if(val.ss+1>v){
                v=val.ss+1;
                val.ss++;
                res=val;
            }
            
        }
    }
    dist[c]=d;
    return res;
}

void solve(){
    int n;
    cin>>n;
    map<int,vector<int>>adj;
    forn(i,n-1){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int dist_f_r[n+1];
    pair<int,int> fval=farthestnode(0,1,adj,dist_f_r,0);
    int a=fval.ff;
    int dist_f_a[n+1];
    pair<int,int> sval=farthestnode(0,a,adj,dist_f_a,0);
    int b=sval.ff;
    int dist_f_b[n+1];
    pair<int,int> tval=farthestnode(0,b,adj,dist_f_b,0);
    map<int,int> vals;


    // dbga(dist_f_a,n+1);
    // dbga(dist_f_b,n+1);
    // int mx=0;
    for(int i=1;i<=n;i++){
        // vals[max(dist_f_a[i],dist_f_b[i])]++;
        cout<<(max(dist_f_a[i],dist_f_b[i]))<<' ';
        // mx=max(mx,max(dist_f_a[i],dist_f_b[i]));
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
