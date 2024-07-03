#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t,n;
    cin>>t;
    map<int,int> tastes;
    list<int> NDE;
    list<int> NDEi;
    while(t--){
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){cin>>arr[i];tastes[arr[i]]+=1;}
        int uniques=0;
        int comparator=1;
        for(map<int,int>::iterator it1=tastes.begin();it1!=tastes.end();++it1){
            if(it1->second<comparator) {NDE.push_back(it1->second);NDEi.push_back(it1->first);}
            //cout<<"Reps "<<it1->first<<" "<<it1->second<<endl;
            comparator++;
            uniques++;
        }
        int red=0;
        NDE.sort();
        comparator=0;
        int uniqueRep=uniques;
        if(NDE.size()==0){cout<<uniques<<endl;tastes.clear();continue;}
        uniques--;
        while(uniques>0){
            if(NDE.front()>=uniques) break;
            else {
                replace(NDE.begin(),NDE.end(),NDE.front(),NDE.front()-1ll);
                if(NDE.front()==0){
                    red++;
                    NDE.pop_front();
                    if(NDE.size()==0) break;
                }
            }
            uniques--;
        }
        cout<<uniqueRep-red<<endl;
        tastes.clear();
        NDE.clear();
    }
}


