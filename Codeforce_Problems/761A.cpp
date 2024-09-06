#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i,n) for(int i=0;i<n;i++)
#define dbgv(v) cout<<#v<<" "<<v<<'\n';
#define dbga(a,n) forn(i,n-1) {cout<<a[i]<<' ';} cout<<a[n-1]<<'\n';


signed main(){
    int a,b;
    cin>>a>>b;
    if(abs(b-a)>1 || (a+b)==0)cout<<"NO";
    else cout<<"YES";

}

