#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i,n) for(int i=0;i<n;i++)
#define dbgv(v) cout<<#v<<" "<<v<<'\n';
#define dbga(a,n) forn(i,n-1) {cout<<a[i]<<' ';} cout<<a[n-1]<<'\n';

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

bool same(int a[],int b[],int l){
    forn(i,l){
        if(a[i]!=b[i]) return false;
    }
    return true;
}

signed main(){
    int t=1,n,l;
    while(t--){
        cin>>n>>l;
        int v1[n];
        int d1[n];
        forn(i,n){
            cin>>v1[i];
        }
        forn(i,n-1){
            d1[i]=v1[i+1]-v1[i];
        }
        d1[n-1]=l-v1[n-1]+v1[0];
        int v2[n];
        int d2[n];
        forn(i,n){
            cin>>v2[i];
        }
        forn(i,n-1){
            d2[i]=v2[i+1]-v2[i];
        }
        d2[n-1]=l-v2[n-1]+v2[0];
        if(same(d1,d2,n)){cout<<"YES\n";return 0;}
        forn(i,n-1){
            shiftL(d1,n,n-1,1);
            if(same(d1,d2,n)){cout<<"YES\n";return 0;}
        }
        cout<<"NO\n";


    }

}
