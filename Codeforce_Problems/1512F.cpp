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
    ll n,c;
    cin>>n>>c;
    ll a[n];
    ll b[n-1];
    forn(i,n){
        cin>>a[i];
    }
    forn(i,n-1){
        cin>>b[i];
    }
    ll m=10000000000;
    ll l=0;
    ll o=0;
    ll cc=c;
    // dbgv(m-10000000000000);
    for(int i=0;i<n;i++){
        if(i!=n-1){
                        // dbgv(o+(cc-l)/a[i]+((cc-l)%a[i]==0?0:1));

            m=min(m,o+(cc-l)/a[i]+((cc-l)%a[i]==0?0:1));
            // dbgv(o);
            // dbgv(l);
            // dbgv(m);
            // cout<<m<=o+(cc-l)/a[i]+((cc-l)%a[i]==0?0:1)<<endl;

            if(l>=b[i]){
                l-=b[i];
                o++;
            } else {
                int v=((b[i]-l)/a[i]+((b[i]-l)%a[i]==0?0:1));
                // dbgv(v);
                l=(a[i]*v+l-b[i]);
                o+=(v+1);
            }
        } else{
            m=min(m,o+(cc-l)/a[i]+((cc-l)%a[i]==0?0:1));
            // dbgv(o);
            // dbgv(l);
            // dbgv(o+(cc-l)/a[i]+((cc-l)%a[i]==0?0:1));
            // dbgv(m);
        }
    }

    cout<<m<<endl;
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
