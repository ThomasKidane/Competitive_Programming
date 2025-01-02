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
    ll n,w;
    cin>>n>>w;
    vector<pair<ll,ll>> items;
    ll mxv=0;
    forn(i,n){
        ll w,v;
        cin>>w>>v;
        items.push_back(make_pair(w,v));
        mxv=max(mxv,v);
    }   
    ll dp[100*mxv+1];
    memset(dp,0,sizeof(dp));
    forn(i,n){
        // dbga(dp,20);
        for(int v=mxv*100;v>=0;v--){
            if(i==0){
                dp[items[i].ss]=items[i].ff;
                break;
            } else {
                if(v==0){
                    if(dp[items[i].ss]!=0){
                        dp[items[i].ss]=min(items[i].ff,dp[items[i].ss]);
                    
                    } else {
                        dp[items[i].ss]=items[i].ff;   
                    }
                    
                } else {
                    if(dp[v]>0 && dp[v]+items[i].ff<=w){
                        if(dp[v+items[i].ss]==0){
                            dp[v+items[i].ss]=dp[v]+items[i].ff;
                        } else {
                            dp[v+items[i].ss]=min(dp[v+items[i].ss],dp[v]+items[i].ff);
                        }
                    }
                }
            }
            // dp[v+items[i].ss]=max(dp[W+items[i].ff],dp[W]+items[i].ss);
        }
    }

    // dbga(dp,mxv*10);
    ll m=0;
    for(int i=1;i<=mxv*100;i++){
        if(dp[i]==0)continue;
        // m=max(dp[i],m);
        m=i;
    }
    cout<<m<<endl;
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
