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
    ll a,b;
    cin>>a>>b;
    // if(a==b){
    //     if(a==0){
    //         cout<<1<<' '<<n<<endl;
    //     return;
    //     } else {
    //         cout<<1<<' '<<n*k<<endl;
    //         return;
    //     }
        
    // }
    ll mi=n*k;
    ll mx=0;
    // upper 
    // if
    for(ll i=abs(a-b);i<=n*k;i+=k){
        mi=min(mi,abs((n*k)/(gcd(i,(n*k)))));
        mx=max(mx,abs((n*k)/(gcd(i,n*k))));
    }
    
    for(ll i=k+abs(b-a);i<=n*k;i+=k){
        mi=min(mi,abs((n*k)/(gcd(i,(n*k)))));
        mx=max(mx,abs((n*k)/(gcd(i,n*k))));
    }

    cout<<mi<<' '<<mx<<endl;
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
