    #include<bits/stdc++.h>
    // #include 

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
        int n,q;
        cin>>n>>q;
        ll a[n][n];
        forn(i,n){
            forn(j,n){
                cin>>a[i][j];
            }
        }
        ll dp[n+1][n+1];

        forn(i,n+1){
            dp[0][i]=0;
        }
        forn(i,n+1){
            dp[i][0]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dp[i][j]=a[i-1][j-1]+dp[i-1][j]-dp[i-1][j-1]+dp[i][j-1];
            }
        }

        
        int x1,y1,x2,y2;
        forn(i,q){
            
            cin>>y1>>x1>>y2>>x2;

            cout<<dp[y2][x2]+dp[y1-1][x1-1]-dp[y2][x1-1]-dp[y1-1][x2]<<endl;
        }
    }

    int main() {
        int T = 1;
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        // cin >> T;
        while(T--){
            solve();
        }
        return 0;
    }

