#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t=0,n;cin>>t;
    map<int,int> Ye;
    while(t--){
        cin>>n;
        Ye.clear();
        int a[n];
        for(int i=0;i<n;i++){cin>>a[i];Ye[a[i]]+=1;}
        int g=0;
        int leftO=0;
        for(map<int,int>::iterator it1=Ye.begin();it1!=Ye.end();it1++){
            Ye[it1->first]+=leftO;
            leftO=0;
            g+=(it1->second/it1->first);
            leftO+=it1->second-(it1->second/it1->first)*it1->first;
        }
        cout<<g<<endl;
    }

}
