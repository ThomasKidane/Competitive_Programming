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
    int val[n];
    forn(i,n){
        cin>>val[i];
    }
    // vector<map<int,int>> vs;//In the dictionary you store the sum, and the eating rate index.
    map<int,int> values;
    map<int,int> valRev;
    int c=1;
    while(m!=0){
        values[m]=c;
        valRev[c]=m;
        c++;
        m*=2;
        m/=3;
        // m*=2;
    }
    // for(int i=c;c<20000;i++){
    //     values[c]=0;
    // }
    // dbgv(valRev[1]);


    map<int,pair<int,int>> dc; // The key is the calorie and the value is the eating rate
    dc[0]=make_pair(1,0);
    forn(i,n){
        map<int,pair<int,int>> dc1;
        // dbgv(i);
        for(auto it=dc.begin();it!=dc.end();it++){
            // dbgv(it->first);
            if(it->second.second==1){
                dc1[(*it).first]=make_pair(1,0);
            } else {
                dc1[(*it).first]=make_pair(it->second.first,1);
            }

            // dc1[(*it).first]=max(0,min(0,(*it).second-1)); // Not eating
            // if(it->second==i-1){
                // dc1[(*it).first+min(valRev[(*it).second-1],val[i])]=(*it).second+1;    
            // }
            // if(dc1[(*it).first+min(valRev[it->second.first],val[i])])
            if(dc1[(*it).first+min(valRev[it->second.first],val[i])].first==0){
                dc1[(*it).first+min(valRev[it->second.first],val[i])]=make_pair(it->second.first+1,it->second.second);
            } else {
                if(dc1[(*it).first+min(valRev[it->second.first],val[i])].first>it->second.first+1 || (dc1[(*it).first+min(valRev[it->second.first],val[i])].first==it->second.first+1 && it->second.second==1)){
                    dc1[(*it).first+min(valRev[it->second.first],val[i])]=make_pair(it->second.first+1,it->second.second);
                }
            }
            
            // dbgv((*it).first)
        }
        dc=dc1;
    }
    int M=0;
    for(auto it=dc.begin();it!=dc.end();it++){
        if(M<it->first)M=it->first;
    }
    cout<<M;
}


int main() {
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
