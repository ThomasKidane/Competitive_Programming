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
    ll n,k;
    cin>>n>>k;
    ll S=0;
    ll d;
    ll mx=0;
    forn(i,n){
        cin>>d;
        if(mx<d)mx=d;
        S+=d;
    }
    ll mv=1;
    for(ll v=2;v<=n;v++){
        if((S+k-(S+k)%v)>=S && (S+k-(S+k)%v)/v>=mx ){mv=v;}
    }
    cout<<mv<<endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
