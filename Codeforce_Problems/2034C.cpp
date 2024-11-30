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

void dfs_makebad(int i,int j,string grid[],int n,int m,vector<vector<bool>> &visited_bad,vector<vector<bool>> &bad){
    visited_bad[i][j]=true;
    if(i-1>=0){
        if(!visited_bad[i-1][j] && grid[i-1][j]=='D'){
            bad[i-1][j]=true;
            dfs_makebad(i-1,j,grid,n,m,visited_bad,bad);
        }
    }
    if(i+1<=n-1){
        if(!visited_bad[i+1][j] && grid[i+1][j]=='U'){
            bad[i+1][j]=true;
            dfs_makebad(i+1,j,grid,n,m,visited_bad,bad);
        }
    }
    if(j-1>=0){
        if(!visited_bad[i][j-1] && grid[i][j-1]=='R'){
            bad[i][j-1]=true;
            dfs_makebad(i,j-1,grid,n,m,visited_bad,bad);
        }
    }
    if(j+1<=m-1){
        if(!(visited_bad[i][j+1]) && grid[i][j+1]=='L'){
            bad[i][j+1]=true;
            dfs_makebad(i,j+1,grid,n,m,visited_bad,bad);
        }
    }
}

bool all_bad(int i,int j,string grid[],int n,int m,vector<vector<bool>> &visited_bad,vector<vector<bool>> &bad){
    bool res=false;
    if(i-1>=0){
        if(!bad[i-1][j]){
            res=true;
        }
    }
    if(i+1<=n-1){
        if(!bad[i+1][j]){
            res=true;
        }
    }
    if(j-1>=0){
        if(!bad[i][j-1]){
            res=true;
        }
    }
    if(j+1<=m-1){
        if(!(bad[i][j+1])){
            res=true;
        }
    }
    return res;
}

void solve(){
    int n,m;
    cin>>n>>m;
    string grid[n];
    forn(i,n){
        cin>>grid[i];
    }

    vector<vector<bool>> bad(n,vector<bool> (m,false));
    vector<vector<bool>> visited_bad(n,vector<bool> (m,false));
    forn(i,n){
        forn(j,m){
            if(i==0){
                if(grid[i][j]=='U'){
                    bad[i][j]=true;
                    dfs_makebad(i,j,grid,n,m,visited_bad,bad);
                }
            }
            if(i==n-1){
                if(grid[i][j]=='D'){
                    bad[i][j]=true;
                    dfs_makebad(i,j,grid,n,m,visited_bad,bad);
                }
            }
            if(j==0){
                if(grid[i][j]=='L'){
                    bad[i][j]=true;
                    dfs_makebad(i,j,grid,n,m,visited_bad,bad);
                }
            }
            if(j==m-1){
                if(grid[i][j]=='R'){
                    bad[i][j]=true;
                    dfs_makebad(i,j,grid,n,m,visited_bad,bad);
                }
            }
        }
    }
    int cnt=0;
    forn(i,n){
        forn(j,m){
            if(!visited_bad[i][j] && all_bad(i,j,grid,n,m,visited_bad,bad)){
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
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
