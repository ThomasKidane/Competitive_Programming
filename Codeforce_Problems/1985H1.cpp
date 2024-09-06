#include<bits/stdc++.h>

using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

#define forn(i,n) for(int i=0;i<n;i++)
#define dbgv(v) cout<<#v<<" "<<v<<endl
#define dbga(a,n) forn(i,n-1) {cout<<a[i]<<' ';} cout<<a[n-1]<<'\n';\

int getV(int x,int y,int n,int m,string sq[],map<int,map<int,bool>> &visited, vector<pair<int,int>> &val){

    if(sq[x][y]=='.')return 0;
    val.push_back(make_pair(x,y));
    visited[x][y]=1;

    int vals=0;
    if(x<n-1){
        if(!visited[x+1][y])vals+=getV(x+1,y,n,m,sq,visited,val);
    }
    if(x>0){
        if(!visited[x-1][y])vals+=getV(x-1,y,n,m,sq,visited,val);
    }
    if(y<m-1){
        if(!visited[x][y+1])vals+=getV(x,y+1,n,m,sq,visited,val);
    }
    if(y>0){
        if(!visited[x][y-1])vals+=getV(x,y-1,n,m,sq,visited,val);
    }

    return vals+1;
    
}

void solve(){
    int n,m;
    cin>>n>>m;
    string sq[n];
    forn(i,n){
        cin>>sq[i];        
    }
    map<int,map<int,bool>> visited;
    int a[n][m]={0};
    forn(i,n){
        forn(j,m)a[i][j]=0;
    }
    cout<<a[0][3]<<endl;
    forn(i,n){
        forn(j,m){
            if(!visited[i][j]){
                if(sq[i][j]=='.'){
                    a[i][j]=1;
                    visited[i][j]=1;
                } else {
                    vector<pair<int,int>> vals;
                    a[i][j]=getV(i,j,n,m,sq,visited,vals);
                    while(!vals.empty()){
                        pair<int,int> p=vals.back();
                        vals.pop_back();
                        a[p.ff][p.ss]=a[i][j];
                    }
                }
            }
        }
    }
    int m=0;
    forn(i,n){
        int S=0;
        forn(j,m){
            S+=a[i];
        }
    }
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
