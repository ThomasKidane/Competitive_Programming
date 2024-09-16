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

ll multiplyMod(ll n){
    ll val=1;
    for(int i=1;i<=n;i+=1){
        val*=2;
        val%=(1000000007);
    }
    return val;
}

void solve(){
    int n;
    cin>>n;
    cout<<multiplyMod(n)<<endl;
}

int main() {
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
