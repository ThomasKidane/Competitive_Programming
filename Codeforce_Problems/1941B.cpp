#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


signed main(){
    int tt,n;cin>>tt;
    while(tt--){
        cin>>n;
        ll a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        bool flag=true;
        for(int i=0;i<n-2;i++){
            if(a[i]<0){flag=false;cout<<"NO"<<'\n';break;}
            else {
                a[i+1]-=2*a[i];
                a[i+2]-=a[i];
                a[i]=0;
            }
        }
        if(flag && a[n-1]==0 && a[n-2]==0)cout<<"YES"<<'\n';
        else if((a[n-1]!=0 || a[n-2]!=0) && flag) cout<<"NO"<<'\n';
    }
}
