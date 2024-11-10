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
    int m,n;
    cin>>m>>n;
    ll s[m];
    forn(i,m){
        cin>>s[i];
    }
    ll l[m];
    forn(i,m){
        cin>>l[i];
    }
    ll dp[n+1][m];
    forn(i,m){
        dp[0][i]=0;
    }
    dp[0][0]=1;
    forn(i,n){
        ll sp=0;
        ll lp=0;
        forn(j,m){
            sp+=(s[j]*dp[i][j]);
            sp%=(1000000007);
            lp+=(l[j]*dp[i][j]);
            lp%=(1000000007);
        }
        forn(j,m){
            dp[i+1][j]=0;
            dp[i+1][j]+=((sp+lp)*s[j]);
            dp[i+1][j]%=(1000000007);
            dp[i+1][j]+=((sp)*l[j]);
            dp[i+1][j]%=(1000000007);
        }
    }

    ll S=0;
    forn(i,m){
        S+=dp[n][i];
        S%=(1000000007);
    }

    cout<<S<<endl;

    

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
