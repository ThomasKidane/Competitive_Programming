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
    ll a[n];
    forn(i,n){
        cin>>a[i];
    }
    sort(a,a+n);
    ll dif[n];
    dif[0]=a[0];
    forn(i,n-1){
        dif[i+1]=a[i+1]-a[i];
    }
    ll ops=0;
    ll v=0;
    int i=0;
    while(v<k){
        ops+=min(k-v,(n-i)*dif[i]);
        v+=min(k-v,(n-i)*dif[i]);
        if(v==k){
            break;
        } else {
            ops+=1;
            i++;
        }
    }
    cout<<ops<<endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
