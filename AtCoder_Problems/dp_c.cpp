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
   int n;
   cin>>n;
   int vals[n][3];
   
   forn(i,n){
    int aa,bb,cc;
    cin>>aa>>bb>>cc;
    	vals[i][0]=aa;
	vals[i][1]=bb;
	vals[i][2]=cc;    
        
        
    }
    int dp[n+1][3];
    // forn(i,3){
    //     dp[0][i]=0;
    // }
    memset(dp,0,sizeof(dp));
    
    for(int j=0;j<n;j++){
        for(int i=0;i<3;i++){//
            for(int z=0;z<3;z++){
                if(z!=i){
                    dp[j+1][i]=max(dp[j+1][i],dp[j][z]+vals[j][i]);
                }
            }
        }
    }
    // forn(i,n+1){
    //     forn(j,3){
    //         cout<<dp[i][j]<<' ';
    //     }
    //     // cout<<dp[0][0]<<endl;
    //     cout<<endl;
    // }
    cout<<max(dp[n][0],max(dp[n][1],dp[n][2]))<<endl;

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

