#include <bits/stdc++.h>
using namespace std;

signed main(){
    int tt;cin>>tt;
    while(tt--){
        string a,b;
        cin>>a>>b;
        int n=a.length();
        bool flag=false;
        for(int i=1;i<n-1;i++){
            if(a[i]=='1' && b[i]=='1'){flag=true;break;}
        }
        if(!flag){
            for(int i=n-2;i>0;i--){
            if(a[i]=='0' && b[i]=='0'){flag=true;break;}
        }
        }

        if(flag)cout<<"YES\n";
        else cout<<"NO\n";
    }
}
