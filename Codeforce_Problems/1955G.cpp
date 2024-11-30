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

int getend(int i,int j,vector<vector<int>> &grid,vector<vector<bool>> &reachable,int d,int n,int m){
    if(i==n-1 && j==m-1){
        return d;
    } else {
        bool some=false;
        if(i+1<=n-1){
            if(grid[i+1][j]%d && reachable[i+1][j]){
                some=true;
                int r=getend(i+1,j,grid,reachable,d,n,m);
                if(r==d){
                    return d;
                }
            }
        }
        if(j+1<=m-1){
            if(grid[i][j+1]%d  && reachable[i][j+1]){
                some=true;
                int r=getend(i+1,j,grid,reachable,d,n,m);
                if(r==d){
                    return d;
                }
            }
        }

        reachable[i][j]=some;
        
    }
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> grid(n,vector<int>(m));
    forn(i,n){
        forn(j,m){
            cin>>grid[i][j];
        }
    }
    int g=__gcd(grid[0][0],grid[n-1][m-1]);
    vector<int> divs;
    for(int i=1;i*i<=g;i++){
        if(g%i==0){
            if(i%i==g){
                divs.push_back(i);
            } else {
                divs.push_back(i);
                divs.push_back(g/i);
            }
        }
    }
    if(g){
        cout<<1<<endl;
        return;
    }
    sort(divs.begin(),divs.end());
    reverse(divs.begin(),divs.end());
    for(int d:divs){
        vector<vector<bool>> reachable(n,vector<bool> (m,true));
        reachable[0][0]=true;
    }
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
