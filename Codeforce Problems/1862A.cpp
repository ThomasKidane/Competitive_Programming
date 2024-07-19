#include <bits/stdc++.h>
using namespace std;

signed main(){
    int tt,n,m;cin>>tt;
    string s="vika";
    while(tt--){
        cin>>n>>m;
        string a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        int d=0;
        bool flag=false;
        for(int j=0;j<m;j++){
            char toB=s[d];
            for(int i=0;i<n;i++){
            if(toB==a[i][j]){d++;break;}
        }
        if(d>=s.length()){flag=true;break;}
        }
        if(flag)cout<<"YES"<<'\n';
        else cout<<"NO\n";

    }
}
