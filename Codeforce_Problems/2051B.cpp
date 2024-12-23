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
    ll n,a,b,c;
    cin>>n>>a>>b>>c;
    ll v=3*(n/(a+b+c));
    ll r=(v/3)*(a+b+c);
    if(r<n){
        v++;
        r+=a;
    }
    if(r<n){
        v++;
        r+=b;
    }
    if(r<n){
        v++;
        r+=c;
    }
    cout<<v<<endl;
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
