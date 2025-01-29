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
#define mk make_pair
const ll MOD=998244353;
void solve(){
    int n;
    cin>>n;
    ll a[n];
    forn(i,n){
        cin>>a[i];
    }
    vector<pair<pair<ll,ll>,pair<ll,ll>>> dp;
    if(a[0]==0){
        dp.push_back(mk(mk(1,0),mk(1,1)));
    } else {
        dp.push_back(mk(mk(0,1),mk(1,1)));
    }
    forn(i,n-1){
        ll t=0;
        ll f=0;
        if(dp.back().ff.ss==a[i+1]){
            t+=dp.back().ff.ff;
        }
        if(dp.back().ss.ss==a[i+1]){
            t+=dp.back().ss.ff;
        }
        t%=MOD;
        dp.push_back(mk(mk(t,a[i+1]),mk((dp.back().ff.ff)%MOD,dp.back().ff.ss+1)));
    }
    // forn(i,n){
    //     cout<<dp[i].ff.ff<<' '<<dp[i].ff.ss<<endl;
    //     cout<<dp[i].ss.ff<<' '<<dp[i].ss.ss<<endl;
    //     cout<<"here"<<endl; 
    // }

    cout<<(dp.back().ff.ff+dp.back().ss.ff)%MOD<<endl;
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
