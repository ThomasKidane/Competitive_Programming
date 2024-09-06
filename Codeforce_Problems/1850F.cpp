#include <bits/stdc++.h>
using namespace std;
#define int long long


signed main(){
    int t=0,n,d;cin>>t;
    map<int,int> factorN;
    while(t--){
        cin>>n;
        factorN.clear();
        int b[n]={0};
        for(int i=0;i<n;i++){
            cin>>d;
            if(d<=n) factorN[d]+=1;
        }
        for(map<int,int>::iterator it1=factorN.begin();it1!=factorN.end();it1++){
            for(int i=(it1->first);i<=n;i+=(it1->first)){
                b[i-1]+=(it1->second);
            }
        }
        int tMax=0;
        for(int i=0;i<n;i++){
            if(b[i]>tMax) tMax=b[i];
        }
        cout<<tMax<<endl;



    }

}





