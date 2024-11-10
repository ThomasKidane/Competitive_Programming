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
    ll S=0;
    forn(i,n){cin>>a[i];S+=a[i];}
    if(n<=2){
        cout<<-1<<endl;
    } else {
        sort(a,a+n);
        // dbga(a,n);
        // dbgv(S);
        // dbgv(a[n/2]+1);
        cout<<max(0ll,2*n*(a[n/2])-S+1)<<endl;
    }
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
