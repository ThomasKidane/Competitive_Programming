#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll modRes(ll k, ll x){
    ll t=1;
    for(int i=0;i<k;i++){
        t*=2ll;
        t=t%(ll)(1e9+7);
    }
    t-=1ll;
    t=((ll)(1e9+7)+t)%(ll)(1e9+7);
    x=t*x;
    return x%(ll)(1e9+7);
}

signed main(){
    int tt,n,k;cin>>tt;
    vector<int> ls;
    while(tt--){
        cin>>n>>k;
        ll a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        ll x=0;
        ll Sum=0;
        for(int i=0;i<n;i++){
            Sum=max(Sum+a[i],0ll);
            x=max(x,Sum);
        }
        Sum=0ll;
        x=x%(ll)(1e9+7);
        for(int i=0;i<n;i++){
            Sum+=a[i];
            Sum=(Sum)%(ll)(1e9+7);
        }

        cout<<((Sum+modRes((ll)k,(ll)x))%(ll)(1e9+7)+(ll)1e9+7)%(ll)(1e9+7)<<'\n';


    }
}
