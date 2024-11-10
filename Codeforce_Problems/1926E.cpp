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
    ll k,n;
    cin>>n>>k;
    ll r=1;
    ll sub=2;
    ll i=0;
    for(i;(i+(r+n)/(r*2))<k;r*=2){
        i+=(r+n)/(r*2);
    }
    // dbgv(r);
    // dbgv(i);
    // dbgv(pow(2,r+1));
    cout<<(k-i-1)*(r*2)+r<<endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
