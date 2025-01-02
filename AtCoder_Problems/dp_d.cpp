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
    forn(i,n){
        ll w,v;
        cin>>w>>v;
        items.push_back(make_pair(w,v));
    }   
    ll dp[w+1];
    memset(dp,0,sizeof(dp));
    forn(i,n){
        for(int W=w-items[i].ff;W>=0;W--){
            dp[W+items[i].ff]=max(dp[W+items[i].ff],dp[W]+items[i].ss);
        }
    }

    ll m=0;
    for(int i=0;i<=w;i++){
        m=max(dp[i],m);
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
