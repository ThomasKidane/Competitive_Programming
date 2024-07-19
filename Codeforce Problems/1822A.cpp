#include <bits/stdc++.h>
using namespace std;


signed main(){
    int tt,n,t;cin>>tt;
    list<vector<int>> vids;
    while(tt--){
        cin>>n>>t;
        int a[n];
        int b[n];
        vids.clear();
        for(int i=0;i<n;i++){cin>>a[i];a[i]+=i;}
        for(int i=0;i<n;i++)cin>>b[i];
        for(int i=0;i<n;i++)vids.push_back(vector<int> {a[i],b[i],i});
        bool flag=true;
        int Max=0,i;
        for(list<vector<int>>::iterator it1=vids.begin();it1!=vids.end();it1++){
            if(Max<(*it1)[1] && (*it1)[0]<=t) {i=(*it1)[2]+1;flag=false;Max=(*it1)[1];}
        }
        if(flag)cout<<-1<<endl;
        else cout<<i<<endl;

    }
}
