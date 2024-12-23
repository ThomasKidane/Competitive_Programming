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
    int n,k;
    cin>>n>>k;
    map<int,vector<int>> mp; // tree,restriction, as independent inputs
    forn(i,n){
        int d;
        cin>>d;
        if(mp[d].empty()){
            mp[d].push_back(1);
        } else {
            mp[d][0]++;
        }
    }
    forn(i,k){
        int l,r,t;
        cin>>l>>r>>t;
        if(mp[l].empty()){
            mp[l].push_back(0);
            mp[l].push_back(t);
        } else {
            mp[l].push_back(t);
        }
        if(mp[r+1].empty()){
            mp[r+1].push_back(0);
            mp[r+1].push_back(-t);
        } else {
            mp[r+1].push_back(-t);
        }
    }

    int c=0;
    int am=0;
    int l=0;
    int b=0;
    map<int,int> lims;
    for(auto it=mp.begin();it!=mp.end();it++){
        // int v=min(it->second[0],l);
        int v=(max(0,c-l));
        c-=v;
        am+=v;
        dbgv(c);
        dbgv(b);
        if(it->ss.size()>1){
            sort(it->ss.begin()+1,it->ss.end());
        }
        for(int i=1;i<it->second.size();i++){
            if(it->ss[i]<0){
                lims[-(it->ss[i])]--;
                if(lims[-(it->ss[i])]==0){
                    lims.erase(-(it->ss[i]));
                }
                if(it->ss[i]==-l){
                    l=0;
                    c=0;
                    b=0;
                }
            } else if(it->ss[i]>0){
                lims[it->ss[i]]++;
                // if(lims[it->ss[i]]==0){
                //     lims.erase(it->ss[i]);
                // }
                
                if(it->ss[i]>(l-c)){
                    b=c;
                    c=0;
                    l=it->ss[i];
                }
            }
        }
        
        c+=it->second[0];
        if(lims.empty()){l=0;}
        // else {
        //     l=prev(lims.end())->ff;
        // }
        v=max(0,c-l);
        c-=v;
        am+=v;
        dbgv(c);
        dbgv(b);
        dbgv(am);
        dbgv(it->ff);
        if(b>0){
am+=max(0,min(b,it->second[0]));
b-=max(0,min(b,it->ss[0]));
        }
        
        
        dbgv(am);
        // dbgv

        // it->second[0]-=v;
        

    }

    cout<<am<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
