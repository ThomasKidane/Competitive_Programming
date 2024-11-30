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
   int n,k;
   cin>>n>>k;
   vector<ll> dp(n+1,100000000000000);
   dp[0]=0;
   dp[1]=0;
   int height[n];
   forn(i,n){
        cin>>height[i];
   }
   
    forn(i,n){
        // dp[i+1]=min(abs(height[i]-(i>0 ? height[i-1] : 0))+dp[i],dp[i+1]);
        for(int j=1;j<=k;j++){
            // cout<<"Hapend"<<endl;
            if(i>=j){
                // dbgv(i-j);
                // dbgv(abs(height[i]-height[i-j]));
                dp[i+1]=min(dp[i-j+1]+abs(height[i]-height[i-j]),dp[i+1]);
            }
            
        }
    }
    // dbga(dp,5);
    cout<<dp[n]<<endl;
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
