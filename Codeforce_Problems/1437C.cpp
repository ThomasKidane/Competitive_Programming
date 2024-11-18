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
    vector<int> a((2*n)+20,0);
    vector<vector<int>> nums((2*n)+20);
    int b[n];
    forn(i,n){
        cin>>b[i];
    }
    sort(b,b+n);
    int dp[n+1][2*n+20];// Minimum penality when first i items are assigned in first j spots, j is filled
    forn(i,2*n){
        dp[0][i]=0;
    }
    for(int i=1;i<=n;i++){
        forn(j,2*n){
            dp[i][j]=INFINITY;
        }
    }
        
    
    // dp[0][]
    // forn(j,2*n+10){
    //     dp[0][j]=abs(b[0]-)
    // }
    for(int i=1;i<=n;i++){
        // for(int )
        for(int j=i;j<2*n;j++){
            dp[i][j]=min(dp[i-1][j-1]+abs(b[i-1]-j),dp[i][j]);
            dp[i][j+1]=min(dp[i][j],dp[i][j+1]);
        }
    }

    int c=1000000;
    forn(j,n){
        c=min(dp[n][j+n],c);
    }

    cout<<c<<endl;
    

}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
