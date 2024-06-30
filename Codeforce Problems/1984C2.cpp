#include <bits/stdc++.h>
using namespace std;
vector<long long> p2(2e5+20);

signed main(){
    p2[0]=1;
    long long placehold=1;
    for(int x=1;x<2e5+20;x++){
        p2[x]=(2ll*p2[x-1])%998244353ll;
    }

    long long t;
    cin>>t;
    long long n;
    long long mn=0,cur_am=0;
    long long n1;
    long long total=0;

    while(t--){
        cin>>n;
        long long arr[n];
        cur_am=0;
        mn=0;
        n1=0;
        total=0;
        for(long long i=0;i<n;i++) cin>>arr[i];
        for(long long i=0;i<n;i++){
            cur_am+=arr[i];
            if(cur_am<mn){mn=cur_am;}
        }
        cur_am=0;
        placehold=1;
        for(long long i=0;i<n;i++){
            cur_am+=arr[i];
            if(cur_am>=0) n1++;
            else if(cur_am==mn){
                    total=((total)+p2[n1+n-i-1ll])%998244353ll;
            }
        }

        if(total==0)total=p2[n];

        cout<<total<<endl;
    }
}



