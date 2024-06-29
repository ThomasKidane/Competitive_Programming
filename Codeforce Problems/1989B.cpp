#include <bits/stdc++.h>
using namespace std;

signed main(){
    int t;cin>>t;
    while(t--){
        string a,b;
        cin>>a>>b;
        int inter=0;
        int same;
        for(int x=0;x<b.length();x++){
            int k=x;
            same=0;
            for(int i=0;i<a.length();i++){
                if(k<b.length() && a[i]==b[k]){
                    k++;
                    same++;
                }
            }
            inter=max(inter,same);
        }
        cout<<a.length()+b.length()-inter<<endl;
    }
}
