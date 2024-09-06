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

int getV(ll x,ll y,ll r,map<int,map<int,bool>> &visited){

    if(x*x + y*y < r*r || (x*x+y*y) >= ((r+1)*(r+1)) || x==0) return 0;

    int vals=0;

    if(visited[x-1][y]!=1){
        visited[x-1][y]=1;
        vals+=getV(x-1,y,r,visited);
    }
    
    if(visited[x][y+1]!=1){
        visited[x][y+1]=1;
        vals+=getV(x,y+1,r,visited);
    }      
    if(visited[x-1][y+1]!=1){
        visited[x-1][y+1]=1;
        vals+=getV(x-1,y+1,r,visited);
    } 
    return vals+1;
    
}

void solve(){
    int n;
    cin>>n;
    map<int,map<int,bool>> visited;
    visited[0][n]=1;
    cout<<4*getV(n,0ll,n,visited)<<endl;
}

int main() {
    int T = 1;
    cin >> T;

    while(T--){
        solve();
    }
    return 0;
}
