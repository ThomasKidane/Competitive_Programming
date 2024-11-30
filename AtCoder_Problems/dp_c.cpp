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
   int a[n];
   int b[n];
   int c[n];
   forn(i,n){
    int aa,bb,cc;
    cin>>aa>>bb>>cc;
        a[i]=aa;
        b[i]=bb;
        c[i]=cc;
    }
    int dp[n+1][3];
    // forn(i,3){
    //     dp[0][i]=0;
    // }
    memset(dp,0,sizeof(dp));
    // forn(i,n){
    //     cout<<dp[0][0]<<endl;
    // }
    forn(j,n){
        forn(i,3){
            forn(z,3){
                if(z!=i){
                    dp[j+1][i]=min()
                }
            }
        }
    }

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

