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

bool comp(vector<int> p1,vector<int> p2){
    return p1[1]<p2[1];
}

bool dfsw(int i,int e,int visited[],bool winner[],map<int,vector<int>>&adj){
    visited[e]++;
    winner[e]=true;
    for(int n:adj[e]){
        if(visited[n]<1){
            dfsw(e,n,visited,winner,adj);
        }
    }
    return winner[e];
}

void solve(){
    int n;
    cin>>n;
    vector<vector<int>> fs(n,vector<int> (3,0));
    forn(i,n){
        cin>>fs[i][0];
    }
    forn(i,n){
        cin>>fs[i][1];
        fs[i][2]=i;
    }
    sort(fs.begin(),fs.end());
    bool can[n];
    map<int,vector<int>> adj;
    bool winner[n]={false};
    winner[fs.back()[2]]=true;
    for(int i=n-1;i>0;i--){
        adj[fs[i-1][2]].push_back(fs[i][2]);
    }
    sort(fs.begin(),fs.end(),comp);
    for(int i=n-1;i>0;i--){
        adj[fs[i-1][2]].push_back(fs[i][2]);
    }
    winner[fs.back()[2]]=true;
    
    int visited[n]={0};
    dfsw(-1,fs.back()[2],visited,winner,adj);
    // for(int i=0;i<n;i++){
    //     if(visited[i]<3){
    //         dfsw(-1,i,visited,winner,adj);
    //     }
    // }
    
    string res="";
    forn(i,n){
        if(winner[i]){
            res+="1";
    } else {
        res+='0';
    }
    }

    cout<<res<<endl;
    
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
