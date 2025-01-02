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
const int MOD=1000000007;
void solve(){
    int n,m;
    cin>>n>>m;
    ll dp[n][m];
    string vals[n];
    forn(i,n){
        cin>>vals[i];
    }
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    bool still=true;
    forn(i,m){
        if(still){
            if(vals[0][i]=='#'){
                still=false;
                dp[0][i]=0;
            }
            else {
                dp[0][i]=1;
            }
        } else {
            dp[0][i]=0;
        }
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(vals[i][j]=='.'){
                // dp[i][j]
                if(j>0){
                    dp[i][j]+=dp[i][j-1];
                    dp[i][j]%=MOD;
                }
                dp[i][j]+=dp[i-1][j];
                dp[i][j]%=MOD;
            } else {
                dp[i][j]=0;
            }
        }
    }

    cout<<dp[n-1][m-1];
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
