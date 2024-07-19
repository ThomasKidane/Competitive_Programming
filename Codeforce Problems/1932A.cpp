#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


signed main(){
    int tt,n;cin>>tt;
    while(tt--){
        cin>>n;
        string s;
        cin>>s;
        int c=0;
        int i=0;
        s+=' ';
        while(true){
            if(i>=n)break;
            if(s[i]=='*')break;
            if(s[i]=='@')c++;
            if(s[i+1]!='*')i++;
            else i+=2;
        }
        cout<<c<<'\n';
    }
}

