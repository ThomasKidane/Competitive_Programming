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

ll dfs(int x,int y,int n,int m,vector<vector<ll>> dp){
    if(y==0){
        return 1;
    } else {
        ll res=0;
        // Not going to above diaional line
        if((x-(m-n)+1)<y){
            res+=dfs(x,y-1,n,m,dp)+1;
        }

        res+=dfs(x-1,y-1,n,m,dp);
        dp[y][x]=res;
        return res;
    }
}   
void solve(){
    int n,m;
    cin>>n>>m;
    // vector<vector<ll>> dp(n+1,vector<ll> (m+1));//n<=m, trying to get to [n][m], going diagonal is matching, going to the right is skipping
    // dp[0][0]=1;
    // cout<<dfs(m,n,n,m,dp)<<endl;
    ll nplusm=1;
    for(ll i=1;i<=m;i++){
        nplusm*=i;
    }
    ll nandm=1;
    for(ll i=1;i<=n;i++){
        nandm*=i;
    }
    for(ll i=1;i<=m-n;i++){
        nandm*=i;
    }
    cout<<nplusm/nandm<<endl;

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
