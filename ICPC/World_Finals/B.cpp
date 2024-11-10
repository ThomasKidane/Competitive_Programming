#include<bits/stdc++.h>

using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

#define forn(i,n) for(int i=0;i<n;i++)
#define dbgv(v) cout<<#v<<" "<<v<<endl
#define dbga(a,n) forn(i,n-1) {cout<<a[i]<<' ';} cout<<a[n-1]<<'\n';

void solve(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,set<int>>> v;
    set<int> elements;
    forn(i,n){
        elements.clear();
        for(int j=0;j<m;j++){
            int d;
            cin>>d;
            elements.insert(d);
        }
        // cout<<"Elee"<<elements.size()<<m<<endl;
        bool s=false;
        vector<int> tob;
        int l=0;
        forn(j,v.size()){
            set<int>res;
            res.clear();
            // cout<<"from"<<endl;
            // for(auto it=v[j].ss.begin();it!=v[j].ss.end();it++){
            //     cout<<v[j].ss.size()<<' ';
            // }
            // cout<<"Done"<<endl;
            set_intersection(v[j].ss.begin(),v[j].ss.end(),elements.begin(),elements.end(),inserter(res,res.begin()));
            if(res.size()>0){
                tob.push_back(j);
            }
        }
        // dbgv(tob.size());
        forn(j,tob.size()){
            v.erase(v.begin()+tob[j]-l);
            l++;
        }
        v.push_back(make_pair(i,elements));
    }
    // cout<<"Arrays"<<endl;
    // dbgv(v.size());
    // for(int i=0;i<v.size();i++){
    //     for(auto it=v[i].ss.begin();it!=v[i].ss.end();it++){
    //         cout<<(*it)<<' ';
    //     }
    //     cout<<"Done"<<endl;
    // }
    forn(i,n){
        bool did=true;
        forn(j,v.size()){
            if(v[j].ff==i){
                cout<<setprecision(15)<<(ld)1/(v.size())<<endl;
                did=false;
                break;
            }
        }
        if(did){
            cout<<0<<endl;
        }
    }
}

int main() {
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
