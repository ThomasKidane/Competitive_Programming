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
    ll n,x,y;
    cin>>n>>x>>y;
    if(n==(n/min(x,y))*(min(x,y))){cout<<(n/min(x,y))<<endl;}
    else cout<<(n/min(x,y))+1<<endl;
    // cout<<ll(ceil(n/(min((ld)x,(ld)y))))<<endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
