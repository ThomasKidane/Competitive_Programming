#include <bits/stdc++.h>
using namespace std;
#define int long long

void solvable(int Ne,int No,int x){
    for(int i=1;i<=No;i+=2){
        if(x-i<=Ne && i<=x) {cout<<"YES"<<endl;return ;}
    }
    cout<<"NO"<<endl;
}


signed main(){
    int t=0,n,Ne,No,x;cin>>t;
    while(t--){
        cin>>n>>x;
        int a[n];
        Ne=0;
        No=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]%2==0) Ne++;
            else No++;
        }
        solvable(Ne,No,x);
    }

}




