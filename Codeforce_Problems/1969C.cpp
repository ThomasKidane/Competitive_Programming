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
    int l,n;
    cin>>n>>l;
    ll a[n];
    for(ll &b:a){
        cin>>b;
    }
    vector<vector<ll>> sums(n+1,vector<ll> (l+1,1000000000000000));
    sums[0][0]=0;
    for(int i=1;i<=n;i++){
        
        for(int j=0;j<=min(l,i-1);j++){
            // Get min add and update while waling
            ll m=INFINITY;
            for(int k=0;k<=j;k++){
                m=min(a[max(i-1-k,0)],m);
                // dbgv(i-k-1);
                // dbgv(j-k);
                // dbgv(i);
                // dbgv(j);
                // dbgv(sums[i-k-1][j-k]);
                sums[i][j]=min(sums[max(i-k-1,0)][j-k]+(k+1)*m,sums[i][j]);
            }
            
        }
    }

    ll m=INFINITY;
    forn(i,l+1){
        m=min(sums[n][i],m);
    }

    cout<<m<<endl;

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
