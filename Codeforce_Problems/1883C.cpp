#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


signed main(){
    int tt,n,k;cin>>tt;
    while(tt--){
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        if(k==2 || k==3 || k==5){
            int res=k;
            for(int i=0;i<n;i++){
                res=min(res,(k-a[i]%k)%k);
            }
            res=res%k;
            cout<<res<<'\n';
        } else {
        int res=k,c=0;
            for(int i=0;i<n;i++){
                res=min(res,(k-a[i]%k)%k);
                if(a[i]%2==0)c++;
            }
            res=res%k;
        res=min(res,max(2-c,0));

        cout<<res<<'\n';
        }

    }
}



