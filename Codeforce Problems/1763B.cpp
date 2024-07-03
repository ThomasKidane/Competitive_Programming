    #include <bits/stdc++.h>
    using namespace std;

    bool sortP(pair<int,int> v1,pair<int,int> v2){
        if(v1.first<v2.first) return true;
        else if(v1.first==v2.first) {
            if(v1.second>v2.second) return true;
            else return false;
        } else return false;

    }

    signed main(){
        int t,n,k,Maxh;cin>>t;
        vector<pair<int,int>> ph;
        vector<pair<int,int>> goodOnes;
        while(t--){
            cin>>n>>k;
            int h[n],p[n];
            for(int i=0;i<n;i++)
                cin>>h[i];
            for(int i=0;i<n;i++)
                cin>>p[i];
            ph.clear();
            goodOnes.clear();
            for(int i=0;i<n;i++)
                ph.push_back(pair<int,int> {p[i],h[i]});
            sort(ph.begin(),ph.end(),sortP);
            Maxh=ph.front().second;
            goodOnes.push_back(ph[0]);
            for(vector<pair<int,int>>::iterator it1=ph.begin();it1!=ph.end();it1++){
                if(Maxh<it1->second) {
                        goodOnes.push_back(pair<int,int> {it1->first,it1->second});Maxh=it1->second;
                }
            }
            int totD=0;
            while(goodOnes.size()>0 && k>0){
                totD+=k;
                while(goodOnes.front().second<=totD && goodOnes.size()>0) goodOnes.erase(goodOnes.begin());
                k-=goodOnes[0].first;
            }
            if(goodOnes.size()==0) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
