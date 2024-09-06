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
int N=120;
int C=120;
bool connected(vector<int> graphs[120][120],int u,int v,int c,vector<int> seen){
    bool f=false;
    forn(i,graphs[c][u].size()){
        if(graphs[c][u][i]==v)return true;
        else if(count(seen.begin(),seen.end(),graphs[c][u][i])>0){
            continue;
        } else {
            seen.push_back(graphs[c][u][i]);
            f=(f || connected(graphs,graphs[c][u][i],v,c,seen));
            if(f)return true;
        }
    }
    return f;
}

//Max mnumber of nodes and colors respectively
void solve(){
    int n,m;
    cin>>n>>m;
    int u,v,c,q;

    vector<int> graphs[120][120];
    forn(i,m){
        cin>>u>>v>>c;
        graphs[c][u].push_back(v);
        graphs[c][v].push_back(u);
    }
    cin>>q;
    forn(i,q){
        cin>>u>>v;
        int res=0;
        forn(i,C){
            vector<int> seen;
            seen.clear();
            seen.push_back(u);
            if(connected(graphs,u,v,i,seen))res+=1;
            //dbga(seen,seen.size());
        }
        cout<<res<<endl;
    }
    
}

int main() {
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
