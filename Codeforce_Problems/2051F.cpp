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

void atm(int n,int m,vector<pair<int,int>>&vals){
    int j=0;
    for(int step=(n+1)/2;step>0;step/=2){
        if(j+step<n){
            while(vals[j+step].ss<=m){
                j+=step;
                if(j+step>=n){
                    break;
                }
            }
        }
    }
    // inside the range, on the left of a range, on the right of a range
    // inside the range
    if(m>=vals[j].ff && m<=vals[j].ss){
        // increase for everything to the left of it by one to the right and vice versa
        vector<pair<int,int>> vv;
        // vv.push_back(vals[0])
        if(j==0){
            // singe or not 
            if(vals[0].ff==vals[1].ss){
                // just extend the left,
                vv.push_back(make_pair(1,1));
                // vals.push_back(make_pair(n,n));
                for(int i=1;i<vals.size();i++){
                    if(vals[i].ff-1<=vv.back().ss){
                        vv.back().ss=vals[i].ss;
                    } else {
                        vv.push_back(vals[i]);
                        vv.back().ff-=1;
                    }
                }
                if(vv.back().ss==n-1){
                    vv.back().ss=n;
                } else {
                    vv.push_back(make_pair(n,n));
                }

                vals=vv;
                return;
            } else {
                vv.push_back(vals.front());
                for(int i=1;i<vals.size();i++){
                    if(vals[i].ff-1<=vv.back().ss){
                        vv.back().ss=vals[i].ss;
                    } else {
                        vv.push_back(vals[i]);
                        vv.back().ff-=1;
                    }
                }
                if(vv.back().ss==n-1){
                    vv.back().ss=n;
                } else {
                    vv.push_back(make_pair(n,n));
                }
                vals=vv;
                return;
            }
        } else {
            if(vals[j].ff==vals[j].ss){
                vv.push_back(vals.front());
                vv.back().ss+=1;
                // vv.push_back(make_pair(1,1));
                for(int i=1;i<vals.size();i++){
                    if(i==j)continue;
                    if(i>j){
                        if(vals[i].ff-1<=vv.back().ss){
                        vv.back().ss=vals[i].ss;
                        } else {
                            vv.push_back(vals[i]);
                            vv.back().ff-=1;
                        }
                    } else {
                        if(vals[i].ss>=vv.back().ff){
                            vv.back().ss=vals[i].ss;
                        } else {
                            vv.push_back(vals[i]);
                            vv.back().ss+=1;
                        }
                    }
                    
                }
                vals=vv;
                return;
            }
        }
    } else {
        vector<pair<int,int>> vv;
        vv.push_back(vals.front());
                // vv.back().ss+=1;
        if(vv.back().ff>m){
            vv.back().ss+=1;            
        } else {
            vv.back().ff-=1;
        }

                // vv.push_back(make_pair(1,1));
        for(int i=1;i<vals.size();i++){
            // if()continue;
            if(vals[i].ff>m){
                if(vals[i].ff-1<=vv.back().ss){
                vv.back().ss=vals[i].ss;
                } else {
                    vv.push_back(vals[i]);
                    vv.back().ff-=1;
                }
            } else {
                if(vals[i].ss>=vv.back().ff){
                    vv.back().ss=vals[i].ss;
                } else {
                    vv.push_back(vals[i]);
                    vv.back().ss+=1;
                }
            }
            
        }
        vals=vv;
        return;
    }
}


void solve(){
    ll n,m,q;
    cin>>n>>m>>q;
    ll a[n];
    forn(i,n){
        cin>>a[i];  
    }
    
    vector<pair<int,int>> vals;
    vals.push_back(make_pair(m,m));
    

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
