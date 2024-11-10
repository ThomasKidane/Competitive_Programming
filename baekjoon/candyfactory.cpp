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
    ll M=0;
    forn(i,n){
        ll d;
        cin>>d;
        S+=d;
        if(M<d)M=d;
    }
    cout<<max((S+k-1)/k,M)*k-S<<endl;
}

int main() {
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
