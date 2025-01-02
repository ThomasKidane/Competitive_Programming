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
    
    if(n&1){
        // ll c=0;
        ll m=(n+1)/2;
        // n/=2;
        ll c=1;
        ll res=0;
        while(n>=k){
            if(n&1){
                res+=c*m;
            }
            c=(c<<1);
            n/=2;
        }
        cout<<res<<endl;
    } else{
        ll m=n+1;
        ll c=1;
        ll res=0;
        n/=2;
        while(n>=k){
            if(n&1){
                res+=c*m;
            }
            c=(c<<1);
            n/=2;
        }
        cout<<res<<endl;

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
