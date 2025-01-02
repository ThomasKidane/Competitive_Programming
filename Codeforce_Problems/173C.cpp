#include<bits/stdc++.h>

using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second
#define int ll

#define forn(i,n) for(int i=0;i<n;i++)
#define dbgv(v) cout<<#v<<" "<<v<<endl
#define dbga(a,n) forn(i,n-1) {cout<<a[i]<<' ';} cout<<a[n-1]<<'\n';

int func(vector<vector<int>>&dp,int x,int y,int b){
    x++;
    y++;
    b--;
    return dp[y+b][x+b]+dp[y-1][x-1]-dp[y+b][x-1]-dp[y-1][x+b];
}

void solve(){
    int n,m;
    cin>>n>>m;
    int a[n][m];
    forn(i,n){
        forn(j,m){
            cin>>a[i][j];
        }
    }
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    forn(i,m+1){
        dp[0][i]=0;
    }
    forn(i,n+1){
        dp[i][0]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=a[i-1][j-1]+dp[i-1][j]-dp[i-1][j-1]+dp[i][j-1];
        }
    }

//     for(int i=0;i<=n;i++){ 
//         for(int j=0;j<=m;j++){
//             cout<<dp[i][j]<<' ';
//         }
//         cout<<endl;
// }

    vector<vector<int>> res(n,vector<int>(m,0));
    // memset(res,0,sizeof(res));
    int mm=-1000000000;
    for(int k=1;k<=min(m,n);k+=2){
        for(int i=0;i<n-k+1;i++){
            for(int j=0;j<m-k+1;j++){
                // if(k&1){
                    res[i][j]=(func(dp,j,i,k)-(k==1 ? 0 : a[i+1][j]+res[i+1][j+1]));
                    if(k>1) mm=max(res[i][j],mm);


            }   
        }
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         for(int k=0;k<=5;k++){
    //             cout<<res[i][j][k]<<' ';
    //         }
    //         cout<<"          ";
    //     }
    //     cout<<endl;
    // }
    // dbgv(func(dp,2,2,1));
    // dbgv()
    // dbgv(dp[4][3]);
    // dbgv(res[1][0][5]);
 
    cout<<mm<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
