#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i,n) for(int i=0;i<n;i++)
#define dbgv(v) cout<<#v<<" "<<v<<'\n';
#define dbga(a,n) forn(i,n-1) {cout<<a[i]<<' ';} cout<<a[n-1]<<'\n';

signed main(){
    int t,n;cin>>t;
    while(t--){
        cin>>n;
        int a[n];
        forn(i,n)a[i]=i+1;
        dbga(a,n);
    }


}


