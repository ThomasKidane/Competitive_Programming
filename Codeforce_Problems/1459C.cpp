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
    ll a[n];
    ll b[m];
    for(ll &v:a){
        cin>>v;
    }
    for(ll &v:b){
        cin>>v;
    }
    ll gcdfall=0;
    for(int i=1;i<n;i++){
        gcdfall=gcd(gcdfall,a[i]-a[0]);
    }

    forn(i,m){
        cout<<gcd(a[0]+b[i],gcdfall)<<' ';
    }
    // cout<<endl;
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
