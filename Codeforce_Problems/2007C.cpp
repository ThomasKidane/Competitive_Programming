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
    ll n,a,b;
    cin>>n>>a>>b;
    ll g=__gcd(a,b);
    ll c[n];
    // ll mi=g+1;
    // ll mx=-1;
    vector<ll> vals;
    forn(i,n){
        cin>>c[i];
        vals.push_back(c[i]%g);
        // mi=min(mi,c[i]%g);
        // mx=max(mx,c[i]%g);
    }
    if(n==1){
        cout<<0<<endl;
        return ;
    }
    
    sort(vals.begin(),vals.end());
    ll m=vals.back()-vals.front();
    // dbga(vals,vals.size());
    forn(i,n-1){
        m=min(vals[i]+g-vals[i+1],m);
    }
    cout<<m<<endl;
    

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
