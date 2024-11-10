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
    ll l,r,k;
    cin>>l>>r>>k;
    // int step=max((l+r)/2,1);
    // ll s=l;
    // for(ll step=max((l+r)/2,1ll); step>0;step/=2){
    //     while()
    // }
    if(r%k==0){
        cout<<max(r/k-l+1,0ll)<<endl;
    } else {
        cout<<max(r/k-l+1,0ll)<<endl;
    }
    
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
