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
    ll n,m,k;
    cin>>n>>m>>k;
    ll dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j]=0;
        }
    }
    ll val[n][m];
    string des[n];
    ll ones[n][m];
    forn(i,n){
        
        forn(j,m){
            cin>>val[i][j];
        }
    }
    forn(i,n){
        cin>>des[i];
    }
    ll S=0;
    forn(i,n){
        forn(j,m){
            if(des[i][j]=='0'){
                val[i][j]*=-1;
                ones[i][j]=-1;
            } else {
                ones[i][j]=1;
            }
            S+=val[i][j];
        }
    }
    // dbgv(S);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dp[i+1][j+1]=ones[i][j]+dp[i+1][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dp[i+1][j+1]=dp[i+1][j+1]+dp[i][j+1];
        }
    }
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=m;j++){
    //         cout<<dp[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }


    ll div=(k*k);
    for(int i=0;i<=n-k;i++){
        for(int j=0;j<=m-k;j++){
            if(abs(dp[i+k][j+k]+dp[i][j]-dp[i+k][j]-dp[i][j+k])==0)continue;
            div=gcd(div,abs(dp[i+k][j+k]+dp[i][j]-dp[i+k][j]-dp[i][j+k]));
            // cout<<abs(dp[i+k][j+k]+dp[i][j]-dp[i+k][j]-dp[i][j+k])<<endl;
        }
    }
    if(S%div==0){
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
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
