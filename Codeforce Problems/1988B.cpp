#include <bits/stdc++.h>
using namespace std;

signed main(){
    int t,n;cin>>t;
    list<char> vals;
    while(t--){
        string s;
        int c0=0,c1=0;
        cin>>n>>s;
        vals.clear();
        vals.push_back(s[0]);
        if(s[0]=='0')c0++;
        else c1++;
        for(int i=1;i<n;i++){
            if(s[i]=='1'){
                vals.push_back(s[i]);
                c1++;
            } else if(vals.back()=='1'){
                vals.push_back(s[i]);
                c0++;
            }
        }
        if(c0>=c1){
            cout<<"No"<<endl;
        }else{
            cout<<"Yes"<<endl;
        }
    }

}
