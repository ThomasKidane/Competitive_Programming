#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i,n) for(int i=0;i<n;i++)
#define dbgv(v) cout<<#v<<" "<<v<<'\n';
#define dbga(a,n) forn(i,n-1) {cout<<a[i]<<' ';} cout<<a[n-1]<<endl;


signed main(){
    int t,n;cin>>t;
    while(t--){
        cin>>n;
        int d,e=0,o=0;
        int os[2*n];
        int es[2*n];
        for(int i=0;i<2*n;i++){
            cin>>d;
            if(d%2==0){es[e]=i+1;e++;}
            else{os[o]=i+1;o++;}
        }
        int ro=0;
        /*dbga(os,o);
        dbga(es,e);*/
        for(int i=1;i<=n-1;i++){
            if(2*i<=o){cout<<os[2*(i-1)]<<" "<<os[2*(i-1)+1]<<endl;ro++;}
            else{cout<<es[2*(i-1-ro)]<<" "<<es[2*(i-1-ro)+1]<<endl;}
        }
    }
}
