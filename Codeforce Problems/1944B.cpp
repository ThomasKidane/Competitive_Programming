
#include <bits/stdc++.h>
using namespace std;

signed main(){
    int tt,n;cin>>tt;
    while(tt--){
        string s,t;
        cin>>n>>s>>t;
        bool one=false,zero=false,flag=true;
        for(int i=0;i<n;i++){
            if(t[i]>s[i] && !one){flag=false;break;}
            if(s[i]>t[i]){one=true;}
            if(s[i]==t[i]){
                if(s[i]=='1'){one=true;}
            }
        }
        if(flag)cout<<"YES\n";
        else cout<<"NO\n";
    }
}
