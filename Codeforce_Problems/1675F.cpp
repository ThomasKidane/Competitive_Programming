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

bool hasthing(int e,int c,map<int,vector<int>>&adj,set<int>&things,vector<bool>&vv){
    bool has=false;
    if(things.find(c)!=things.end()){
        has=true;
    }

    for(int n:adj[c]){
        if(n!=e){
            has|=hasthing(c,n,adj,things,vv);
        }
    }

    vv[c]=has;
    return has;
}

void hasitem(int e,int c,map<int,vector<int>>&adj,vector<bool>&things,vector<bool>&vv,int& counter){
    bool has=false;
    // if(things.contain(c)){
    //     has=true;
    // }

    for(int n:adj[c]){
        if(n!=e ){
            if(vv[n]){
                counter++;
                hasitem(c,n,adj,things,vv,counter);
            } else if(things[n]){
                counter+=2;
                hasitem(c,n,adj,things,vv,counter);
            }
            // has|=hasthing(c,n,adj,things,vv);
        }
    }

    // vv[c]=has;
    // return has;
}




void solve(){
    int k,n;
    cin>>n>>k;
    int x,y;
    cin>>x>>y;
    set<int> things;
    for(int i=0;i<k;i++){
        int d;
        cin>>d;
        things.insert(d);
    }
    map<int,vector<int>> adj;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> hasthings(n+1,false);
    vector<bool> hasend(n+1,false);

    set<int> where;
    where.insert(y);
    hasthing(-1,x,adj,where,hasend);
    hasthing(-1,x,adj,things,hasthings);
    int counter=0;
    hasitem(-1,x,adj,hasthings,hasend,counter);
    // dbga(hasthings,n+1);
    // dbga(hasend,n+1);

    cout<<counter<<endl;
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
