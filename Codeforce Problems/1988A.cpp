#include <bits/stdc++.h>
using namespace std;

signed main(){
    int t;cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int c=0;
        while(n>1){
            n-=(k-1);
            c++;
        }
        cout<<c<<endl;

    }

}
