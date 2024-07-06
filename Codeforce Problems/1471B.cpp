#include <bits/stdc++.h>
using namespace std;
#define int long long


signed main(){
    int t,n,d,x;cin>>t;
    list<pair<int,int>> chain;
    while(t--){
        chain.clear();
        cin>>n>>x;
        int Sum=0;
        for(int i=0;i<n;i++){
            cin>>d;
            chain.push_back(pair<int,int> {1,d});
            Sum+=d;
        }
        for (list<pair<int,int>>::iterator it1=chain.begin();it1!=chain.end();it1++){
            if((it1->second)%x==0){
                Sum+=(it1->first)*(it1->second);
                chain.push_back(pair <int,int> {x*(it1->first),(it1->second)/x});
            } else break;
        }
        cout<<Sum<<endl;


    }


}

