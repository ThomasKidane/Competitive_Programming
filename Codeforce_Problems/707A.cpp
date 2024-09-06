#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i=0;i<n;i++)

signed main(){
    int t,n,m;cin>>t;
    while(t--){
        cin>>n>>m;
        char a[n][m];
        bool flag=false;
        forn(i,n){if(flag)break; ;forn(j,m){
            cin>>a[i][j];
            if(a[i][j]!='W' && a[i][j]!='B'){flag=true;cout<<"#Color";break;}
        }}
        if(!flag)cout<<"#Black&White";
    }
}
