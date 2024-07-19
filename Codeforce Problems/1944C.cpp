#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forn(i,n) for(int i=0;i<n;i++)
#define dbgv(v) cout<<#v<<" "<<v<<'\n';
#define dbga(a,n) forn(i,n-1) {cout<<a[i]<<' ';} cout<<a[n-1]<<'\n';

signed main(){
    int tt;cin>>tt;
    ll n,x;
    while(tt--){
        cin>>n>>x;
        ll a[n];
        ll psum[n+1]={0};
        for(int i=0;i<n;i++){
            cin>>a[i];
            psum[i+1]=psum[i]+a[i];
        }
        ll Sum=((n+1)*n)/2;
        ll cur=0;
        //dbga(psum,n+1);
        //dbga(a,n);
        int l=0;
        for(int i=0;i<n;i++){
            cur+=psum[i+1]-psum[i];
            //cout<<"Before ";
            //dbgv(cur);
            if(cur>x){
                    Sum-=i;cur=0;cout<<"By "<<i<<endl;
                    for(int j=i-1;j>0;j--){
                        if(psum[i+1]-psum[j]<=x){
                            Sum+=1;
                            dbgv(i);
                            dbgv(j);
                        }else{
                        break;}
                    }
                    }
            //cout<<"After ";
            //dbgv(cur);
        }
        for(int i=0;i<n;i++){
            if(a[i]>x){Sum-=1;cout<<"By one"<<endl;}
        }
        cout<<Sum<<endl;
    }
}
