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
    ll a[n];
    forn(i,n)cin>>a[i];
    ll m=0;
    forn(i,n-2)m+=a[i];
    a[n-2]-=(m);
    a[n-1]-=a[n-2];
    cout<<a[n-1]<<endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
