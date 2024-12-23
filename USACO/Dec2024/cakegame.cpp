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
    int n;
    cin>>n;
    ll a[n];
    ll pref[n+1];
    pref[0]=0;
    forn(i,n){
        cin>>a[i];
        pref[i+1]=pref[i]+a[i];
    }
    ll m=pref[n];
    for(int i=0;i<=n/2-1;i++){
        // dbgv(i);
        m=min(pref[n/2+1+i]-pref[i],m);
    }
    cout<<m<<' '<<pref[n]-m<<endl;
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
