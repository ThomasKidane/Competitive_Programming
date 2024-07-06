#include <bits/stdc++.h>
using namespace std;
#define int long long


signed main(){
    int t,a,b,n;cin>>t;
    while(t--){
        cin>>a>>b>>n;
        int counter=0;
        while(a<=n && b<=n){
            if(a+b>n) {cout<<counter+1<<endl;break;}
            else {
                if(a>b) b+=a;
                else a+=b;
                counter++;
            }
        }

    }


}



