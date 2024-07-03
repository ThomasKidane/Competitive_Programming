#include <bits/stdc++.h>
using namespace std;

signed main(){
    int t;cin>>t;
    int a,b,l,ma,mb;
    set<int> ks;
    while(t--){
        cin>>a>>b>>l;
        ma=1;
        mb=1;
        ks.insert(l);
        while(l%(int)(pow(a,ma))==0){
            ks.insert(l/(int)(pow(a,ma)));
            ma++;
        }
        ma--;
        while(l%(int)(pow(b,mb))==0){
            ks.insert(l/(int)(pow(b,mb)));
            mb++;
        }
        mb--;
        for(int x=1;x<=ma;x++){
            for(int y=1;y<=mb;y++){
                if(l%(int)(pow(b,y)*pow(a,x))==0)
                    ks.insert(l/(int)(pow(b,y)*pow(a,x)));
            }
        }
        cout<<ks.size()<<endl;
        ks.clear();
    }
}
