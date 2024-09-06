#include <bits/stdc++.h>
using namespace std;
#define int long long


signed main(){
    int t=0,n;cin>>t;
    while(t--){
        cin>>n;
        if(n%2==0){cout<<"NO"<<endl;}
        else {
            cout<<"YES"<<endl;
            int r=2*n;
            for(int i=1;i<=n;i+=2){
                cout<<i<<" "<<r--<<endl;
            }
            for(int i=2;i<n;i+=2){
                cout<<i<<" "<<r--<<endl;
            }
        }
    }

}




