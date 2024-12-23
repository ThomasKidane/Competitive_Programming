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

int MOD=998244353;

// int multiply(int a,int b){
//     a%=MOD;
//     b%=MOD;
//     return (int)(((ll)a*b)%MOD);
// }
// int add(int a,int b){
//     a%=MOD;
//     b%=MOD;
//     return (int)(((ll)a+b)%MOD);
// }
int add(int x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
  return x;
} 
 
int multiply(int x, int y) {
  return x * 1LL * y % MOD;
}

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    int s=0;
    forn(i,n){
        cin>>a[i];
        s+=a[i];        
    }
    sort(a.begin(),a.end());
    vector<vector<int>> dp(s+1,vector<int> (n+1,0));
    // forn(i,s+1){
    //     forn(j,n+1){
    //         dp[i][j]=0;
    //     }
    // }
    dp[0][0]=1;
    vector<vector<int>> dps(n+1,vector<int> (s+1,0));
    // forn(i,n+1){
        // forn(j,s+1){
            // dps[i][j]=0;
            // if(j==0){
                dps[0][0]=1;
            // }
        // }
    // }
    
    for(int i=0;i<n;i++){
        for(int j=s;j>=0;j--){
            if(j+a[i]<=s){
                dps[i+1][j+a[i]]=add(dps[i][j],dps[i][j+a[i]]);
            }
            dps[i+1][j]+=add(dps[i+1][j],dps[i][j]);
        }
        // for(int j=0;)
    }

    for(int i=0;i<n;i++){
        // to all the values
        for(int j=s-a[i];j>=0;j--){
            // for(int ii=0;ii<=i;ii++){
                dp[j+a[i]][i+1]=add(dps[i][j],dp[j+a[i]][i+1]);
            // }            
        }
    }
    // forn(i,s+1){
    //     forn(j,n+1){
    //         cout<<dps[j][i]<<' ';
    //     }
    //     cout<<endl;
    // }
    int ans=0;
    for(int i=0;i<=s;i++){
        for(int j=0;j<=n;j++){
            ans=add(ans,multiply(max((i+1)/2,(j==0? 0 : a[j-1])),dp[i][j]));
        }
    }

    cout<<ans<<endl;
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
