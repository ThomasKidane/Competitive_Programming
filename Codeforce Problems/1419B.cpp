#include <bits/stdc++.h>
using namespace std;
#define int long long


signed main(){
    int t,x;cin>>t;
    while(t--){
        int counter=1;
        int res=1;
        cin>>x;
        while(x>=(res)*(res+1)/2){
            x-=(res)*(res+1)/2;
            counter++;
            res=(int)pow(2,counter)-1ll;
        }
        cout<<counter-1<<endl;

    }


}


