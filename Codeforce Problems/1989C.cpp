#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t;
    cin>>t;
    int n=0;
    int a,b;
    while (t--){
        cin>>n;
        int arr[n];
        int brr[n];
        a=0,b=0;
        int aSpec=0,bSpec=0,difsSum=0,pos=0,neg=0;
        int sumA=0,sumB=0;
        int ans;
        for(int x=0;x<n;x++){
            cin>>arr[x];
            sumA+=arr[x];
        }
        for(int x=0;x<n;x++){
            cin>>brr[x];
            sumB+=brr[x];
        }
        for(int x=0;x<n;x++){
            if(arr[x]!=brr[x]){
                if(arr[x]>brr[x]) aSpec+=arr[x];
                else bSpec+=brr[x];
            }
            else if(arr[x]==0 && brr[x]==0) continue;
            else {
                if (arr[x]==1) pos++;
                else neg++;
                difsSum+=arr[x];
            }
        }
        ans=min(aSpec+difsSum,bSpec);
        a=aSpec;
        b=bSpec;
        if(pos>0 && neg>0){
            for(int i=0;i<=pos;i++){
                for(int x=0;x<=neg;x++){
                    ans=max(min(a+i-x,b+(pos-i)-(neg-x)),ans);
                }
            }
        } else if(pos==0){
            for(int x=0;x<=neg;x++){
                    ans=max(ans,min(a-x,b-(neg-x)));
            }
        } else {
            for(int i=0;i<=pos;i++){
                ans=max(ans,min(a+i,b+(pos-i)));
            }
        }



        cout<<ans<<endl;

    }

}



