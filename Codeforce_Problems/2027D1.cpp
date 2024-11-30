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
    cin>>n>>m;
    int a[n];
    int b[m];
    forn(i,n){
        cin>>a[i];
    }
    forn(i,m){
        cin>>b[i];
    }
    vector<vector<pair<ll,ll>>> dp(n+1,vector<pair<ll,ll>> (m+1));
    forn(i,n){
        forn(j,m+1){
            // dbgv(i);
            // dbgv(j);
            dp[i+1][j]=make_pair(INFINITY-1000000000,0);
        }
    }

    dp[0][0]=make_pair(0,0);
    

    // forn(j,m+1){
    //     // Removed nothing
    //     dp[0][j]=0ll;
    // }
    // dbgv(dp[0][1]+1);
    // dp[1][0]=INFINITY;
    // forn(i,n){
    //     forn(j,m){
    //         cout<<dp[i][j].ff<<' ';
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;

    forn(i,n){
        forn(j,m){
            // dbgv(b[j]);
            // Add to previous
            // if(b[j]>=dp[i][j].ss+a[i]){
            if(dp[i+1][j].ff>dp[i][j].ff && b[j]>=dp[i][j].ss+a[i] && dp[i][j].ss>0){
                // Packing in without costing anything
                dp[i+1][j]=make_pair(dp[i][j].ff,dp[i][j].ss+a[i]);
            } 

            if(dp[i+1][j].ff>dp[i][j].ff+(m-1-j) && b[j]>=a[i]){
                dp[i+1][j]=make_pair(dp[i][j].ff+(m-1-j),a[i]);
            }
                    // dp[i+1][j]=make_pair(dp)
            if(j!=0){
                if(dp[i+1][j-1].ff<dp[i+1][j].ff && b[j]>=a[i]){
                    dp[i+1][j]=make_pair(dp[i+1][j-1].ff,a[j]);
                }
                if(dp[i+1][j].ff>dp[i][j-1].ff+(m-1-j) && b[j]>=a[i]){
                    dp[i+1][j]=make_pair(dp[i][j-1].ff+(m-1-j),a[i]);
                }
            }
            
            // }
            // Make new from old

            // Make new new

        }
    }
    forn(i,n+1){
        forn(j,m){
            cout<<dp[i][j].ff<<' ';
        }
        cout<<endl;
    }
    cout<<endl;
    ll mm=9223372036854775807ll;
    forn(i,m){
        if(dp[n][i].ff>=0){
            mm=min(mm,max(0ll,dp[n][i].ff));
        }
      
    }
    if(mm==9223372036854775807 || mm==-9223372036854775808 || mm==-9223372036854775807){
        cout<<-1<<endl;
    } else {
        // cout<<"This"<<endl;
        cout<<mm<<endl;
    }
    


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
