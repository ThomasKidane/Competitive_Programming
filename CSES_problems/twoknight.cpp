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
    ll n;
    cin>>n;
    for(ll j=1;j<=n;j++){
        ll red=0;
        ll i=j*j;
        red=(j-1)*(j-2)*4;
        //dbgv(red);
        ll res=((i)*(i-1)/2)-red;
        cout<<res<<endl;
    }
    
}

int main() {
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
