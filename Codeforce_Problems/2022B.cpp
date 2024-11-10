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
    int n,x;
    cin>>n>>x;
    ll a[n];
    ll m=0;
    ll s=0;
    forn(i,n){
        cin>>a[i];
        if(m<a[i])m=a[i];
        s+=a[i];
    }
    
    cout<<max(m,(s+x-1)/x)<<endl;
    
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
