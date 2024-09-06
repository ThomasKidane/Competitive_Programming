#include <bits/stdc++.h>
using namespace std;
#define int long long

void shiftL(int a[],int t,int n,int l){
    int Ret[t];
    for(int i=l;i<=n;i++){
        Ret[i-l]=a[i];
    }
    for(int i=0;i<l;i++){
        Ret[n-l+i+1]=a[i];
    }
    for(int i=n+1;i<t;i++){
        Ret[i]=a[i];
    }
    for(int i=0;i<t;i++){
        a[i]=Ret[i];
    }
}

signed main(){
    int t=0,n;cin>>t;
    string s;
    map<char,int> alph;
    while(t--){
        cin>>n;
        int t=n;
        int a[t];
        for(int i=0;i<n;i++)cin>>a[i];
        int b[t];
        int o[t]={0};


        while(--n){
            o[n]=(find(a,a+n+1,n+1)-a+1)%(n+1);
            shiftL(a,t,n,o[n]);

        }
        for(int i=0;i<t;i++){
            cout<<o[i]<<" ";
        }
        cout<<"\n";

    }

}


