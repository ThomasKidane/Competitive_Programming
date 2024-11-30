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
    string s[n];
    for(string &row:s){
        cin>>row;
    }
    ll dp[n][n];
    
    forn(i,n){
        forn(j,n){
            
            dp[i][j]=0;
            // if(i==0 || j==0){
            //     dp[i][j]=1;
            // }
        }
    }
    if(s[0][0]!='*'){
        dp[0][0]=1;
    }
    
    forn(i,n){
        forn(j,n){
            if(s[i][j]!='*'){
                if(i-1>=0){
                    dp[i][j]+=dp[i-1][j];
                    dp[i][j]%=((ll)1e9+7);
                }
                if(j-1>=0){
                    dp[i][j]+=dp[i][j-1];
                    dp[i][j]%=((ll)1e9+7);
                }
            }
        }
    }
    cout<<dp[n-1][n-1]; 

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
