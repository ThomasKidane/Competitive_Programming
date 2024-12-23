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
    ll k;
    cin>>n>>m>>k;
    int a[n][m];
    forn(i,n){
        forn(j,m)cin>>a[i][j];
    }

    vector<vector<ll>> dp(n+1,vector<ll>(m,(ll)1e16));
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<m;j++){
    //         dp[i][j]=1e16;
    //     }
    // }
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        for(int shift=0;shift<m;shift++){
            vector<ll> vals(m,0);
            vals[0]=k*shift+(ll)a[i-1][shift%m]+dp[i-1][0];
            // dbgv(dp[i-1][0]);
            // dbgv(i-1);
            // dbgv(k);
            // dbgv(shift*k);
            
            // dbgv(k*shift+(ll)a[i][shift%m]+dp[i-1][0]);
            // dbgv(min(vals[0],dp[i][0]));
            dp[i][0]=min(vals[0],dp[i][0]);
            for(int j=1;j<m;j++){
                vals[j]=min(k*shift+(ll)a[i-1][(shift+j)%m]+dp[i-1][j],vals[j-1]+(ll)a[i-1][(shift+j)%m]);
                dp[i][j]=min(dp[i][j],vals[j]);
            }
        }       
    }

    // forn(i,n+1){
    //     forn(j,m){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    cout<<dp[n][m-1]<<endl;
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
