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
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<ll>> dp(n,vector<ll> (n,LLONG_MAX/21));
    forn(i,n){dp[i][i]=0;}
    bool done[n][n];
    forn(i,m){
        int a,b;
        ll w;
        cin>>a>>b>>w;
        a--;
        b--;
        done[a][b]=true;
        // done[b][a]=true;
        dp[a][b]=min(dp[a][b],w);
        dp[b][a]=min(dp[b][a],w);
    }
    
    // Iterate betwen very pair of veritices and see if you can speed it up by using other nodes as intermediaries
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                // if(dp[i][j]>dp[i][k]+dp[k][j]){
                //     // done[i][j]=true;
                //     // done[j][i]=true;
                    
                //     // dp[j][i]=min(dp[j][i],dp[j][k]+dp[k][i]);
                // }
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         for(int k=0;k<n;k++){
    //             // if(dp[i][j]>dp[i][k]+dp[k][j]){
    //             //     // done[i][j]=true;
    //             //     // done[j][i]=true;
                    
    //             //     // dp[j][i]=min(dp[j][i],dp[j][k]+dp[k][i]);
    //             // }
    //             dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
    //         }
    //     }
    // }
    
    forn(i,q){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        if(dp[a][b]>=LLONG_MAX/22){
            cout<<-1<<endl;
        } else {
            cout<<dp[a][b]<<endl;
        }
        
    }
    

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
