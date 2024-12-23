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
    ll n,x,y;
    cin>>n>>x>>y;
    ll a[n];
    ll S=0;
    forn(i,n){
        cin>>a[i];
        S+=a[i];
    }
    sort(a,a+n);
    ll ans=0;
    for(int i=0;i<n-1;i++){
        if(S-a[i]<x){
            break;
        } else {
            
            // int j=lower(a,a+n,(y-))
            if(S-a[i]-a[n-1]>y){
                continue;
            } else {
                // dbgv(i);
                // dbgv(a[i]);
                // dbgv(a[n-1]);
                // dbgv(S);
                // dbgv(S-a[i]-a[n-1]);
                // greatest val, lower than equal to S-a[i]-x;
                int r=0;
                for(int step=max(1,(int)(n/2));step>0;step/=2){
                    if(r+step<=n-1){
                        while(a[r+step]<=(S-a[i]-x)){
                            r+=step;
                            if(r+step>n-1){
                                break;
                            }
                        }
                    }
                }
                // int r=lower_bound(a,a+n,(S-a[i]-x))-a;
                // dbgv(r);
                int l;
                if(S-a[i]>y){
                    // cout<<"ll"<<endl;
                    // dbgv(y-(S-a[i]));
                    // greatest val
                    l=lower_bound(a,a+n,(S-a[i])-y)-a;
                    l=max(i+1,l);
                } else {
                    l=i+1;
                }
                // dbgv(l);

                // cout<<"rea"<<endl;
                // dbgv(r);
                // dbgv(l);
                // cout<<"rend"<<endl;
                if(r>=l && l>i){
                    // dbgv(r);
                    // dbgv(l);
                    ans+=(r-l+1);
                }
            }
        }
    }

    cout<<ans<<endl;

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
