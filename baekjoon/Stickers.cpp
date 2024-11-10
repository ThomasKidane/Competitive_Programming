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
    int dp[2][3];// The column and the action type done and the row

    forn(i,2){
        forn(j,3){
            dp[i][j]=0;
        }
    }
    int val1[n];
    int val2[n];
    forn(i,n){
        cin>>val1[i];
    }
    forn(i,n){
        cin>>val2[i];
    }
    bool flip=true;

    for(int i=1;i<=n;i++){
        if(flip){
            // For 0 take the max from all values
            dp[1][0]=max(dp[0][0],max(dp[0][1],dp[0][2]));
            // dp[i][0]=max(dp[i-1][0][1],max(dp[i-1][1][1],dp[i-1][2][1]));
            dp[1][1]=max(dp[0][0]+val1[i-1],dp[0][2]+val1[i-1]);
            dp[1][2]=max(dp[0][0]+val2[i-1],dp[0][1]+val2[i-1]);    
        } else {
            // For 0 take the max from all values
            dp[0][0]=max(dp[1][0],max(dp[1][1],dp[1][2]));
            // dp[i][0]=max(dp[i-1][0][1],max(dp[i-1][1][1],dp[i-1][2][1]));
            dp[0][1]=max(dp[1][0]+val1[i-1],dp[1][2]+val1[i-1]);
            dp[0][2]=max(dp[1][0]+val2[i-1],dp[1][1]+val2[i-1]);    
        }

        flip=!flip; 
        
    }
    // forn(i,n+1){
    //     cout<<dp[i][0]<<' ';
    // }
    // cout<<endl;

    int m=0;
    forn(i,3){
        if(flip){
            
        } else {
            if(m<dp[1][i])m=dp[1][i];
        }
        
    }

    cout<<m<<endl;



}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
