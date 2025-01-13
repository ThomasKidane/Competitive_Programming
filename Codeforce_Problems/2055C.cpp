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
void solve(){
    int n,m;
    cin>>n>>m;
    string path;
    cin>>path;
    ll grid[n][m]; // n - numeber of rows, m - numebr of columsn
    ll sc[m];
    ll sr[n];
    memset(sc,0,sizeof(sc));
    memset(sr,0,sizeof(sr));

    forn(i,n){
        forn(j,m){
            cin>>grid[i][j];
            sc[j]+=grid[i][j];
            sr[i]+=grid[i][j];
        }
    }

    int c1=0,c2=0;

    forn(i,n+m-2){
        if(path[i]=='D'){
            c1++;
            // c2-1 is what I want to change
            grid[c1-1][c2]=-sr[c1-1];
            sc[c2]+=grid[c1-1][c2];
        } else {
            c2++;
            // c2-1 is what I want to change
            grid[c1][c2-1]=-sc[c2-1];
            sr[c1]+=grid[c1][c2-1];
        }
    }
    grid[n-1][m-1]=-sc[m-1];

    c1=0;
    c2=0;
    forn(i,n){
        forn(j,m){
            cout<<grid[i][j]<<' ';
        }
        cout<<endl;
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
