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
    ll n,r;
    cin>>n>>r;
    map<ll,map<ll,int>> site; // pointv,number of elements it has, the element it has, Contains the latest ranges with the number of elements it touches and the exact numbers it touches
    int s=n;
    vector<ll> vals(n);
    forn(i,n){
        ll d;
        cin>>d;
        vals[i]=d;
        site[d-r][d]++;
        site[d+r+1][d]--;
    }
    
    vector<ll> moves;
    map<ll,int> toB;
    int t=45;
    while(s>0 && t--){
        toB.clear();
        int m=0; // max intersections
        int cur=0;
        for(auto it=site.begin();it!=site.end();it++){
            for(auto it1=it->ss.begin();it1!=it->ss.end();it1++){
                cur+=it1->ss;
            }
            if(cur>m)m=cur;
        }
        cur=0;
        s-=m;
        map<ll,int> goingM;
        
        for(auto it=site.begin();it!=site.end();it++){
            
            for(auto it1=it->ss.begin();it1!=it->ss.end();it1++){
                cur+=it1->ss;
                goingM[it1->ff]=it1->ss;
            }
            
            if(cur==m){

                moves.push_back(it->ff);
                // dbgv(it->ff);
                
                for(auto it1=goingM.begin();it1!=goingM.end();it1++){
                    
                    if(it1->second>0){                        
                        // cout<<"Her"<<endl;
                        toB[it1->ff]=1;
                        
                    }
                    
                }
                
                break;
            }
        }
        goingM.clear();
        // if(!falk)break;
        for(auto it=site.begin();it!=site.end();it++){
            // for(auto it1=toB.begin();it1!=toB.end();it1++){                
            //     // auto it2=it->ss.find(it1->ff);
            //     // if (it2 != it->ss.end()) {
            //         it->ss.erase(it1->ff);
            //     // }

            // }
            for(auto it1=it->ss.begin();it1!=it->ss.end();it1++){
                if(toB[it1->ff]){
                    it1->ss=0;
                }
                // cur+=it1->ss;
            }
        }

        

    }
    cout<<moves.size()<<endl;
    forn(i,moves.size()){
        cout<<moves[i]<<' ';
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
