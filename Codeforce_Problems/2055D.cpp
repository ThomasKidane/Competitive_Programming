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
    ll n,k,l;
    cin>>n>>k>>l;
    ll a[n];
    forn(i,n){
        cin>>a[i];
        a[i]*=2;
    }   
    // int cur=lower_bound(a,a+n,-k)-a;
    ll p=0;
    int cur=0;
    ll t=0;
    // dbgv(k);
    k*=2;
    l*=2;
    if(a[0]==0){
        p+=k;
        while(true){
            int j=lower_bound(a,a+n,p-k+1)-a;
            // dbgv(j);
            if(j<n && j>=0){
                p=a[j]+k;
                // dbgv(p);
            } else {
                break;
            }

        }
    }
    if(lower_bound(a,a+n,p-k+1)-a>=n){
        cout<<max(0ll,l-p)<<endl;
        return;
    }
    while(true){
        
    }
    // cout<<p<<endl;

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
