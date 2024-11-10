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

int next(int by,int bx,int n,int m, string rows[],vector<vector<bool>> &seen){
    for(int i=-1;i<2;i++){
        for(int j=-1;j<2;j++){
            if(by+i>=0 && by+i<n && bx+j>=0 & bx+j<m){
                if(!seen[by+i][bx+j] && rows[by+i][bx+j]=='#'){
                    seen[by+i][bx+j]=true;
                    next(by+i,bx+j,n,m,rows,seen);
                }
            }

        }
    }
    return 1;
}   

void solve(){
    int n,m;
    cin>>n>>m;
    string rows[n];
    vector<vector<bool>> seen(n,vector<bool>(m,false));
    int c=0;
    forn(i,n){
        cin>>rows[i];
    }
    forn(i,n){
        forn(j,m){
            if(rows[i][j]=='#'&&!seen[i][j]){
                seen[i][j]=true;
                next(i,j,n,m,rows,seen);
                c++;
            }
        }
    }
    cout<<c<<endl;
}

int main() {
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
