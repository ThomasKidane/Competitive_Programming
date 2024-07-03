#include <bits/stdc++.h>
using namespace std;

bool sortV(pair<int,double> p1,pair<int,double> p2){
    return p1.second<p2.second;
}

signed main(){
    int t;cin>>t;
    int n,d,l,ma,mb;
    vector<pair<int,double>> vals;
    map<int,double> freq;
    while(t--){
        cin>>n;
        for(int x=0;x<n;x++){
            for(int y=0;y<n-1;y++){
                cin>>d;
                freq[d]+=(double)y/(n-1);
            }
        }
        for(map<int,double>::iterator it1=freq.begin();it1!=freq.end();it1++){
            vals.push_back(pair<int,double> {it1->first,it1->second});
        }
        sort(vals.begin(),vals.end(),sortV);
        for(vector<pair<int,double>>::iterator it1=vals.begin();it1!=vals.end();it1++){
            cout<<it1->first<<" ";
        }
        cout<<endl;
        vals.clear();
        freq.clear();
    }
}
