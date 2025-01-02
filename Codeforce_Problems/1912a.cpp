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
    ll x,k;
    cin>>x>>k;
    vector<vector<vector<ll>>> lss;
    forn(i,k){
        int d;
        cin>>d;
        bool done=false;
        vector<ll> ls;
        forn(j,d){
            ll y;
            cin>>y;
            
            if(y>0){
                if(!done){
                    x+=y;
                } else {
                    ls.push_back(y);
                }
            } else {
                done=true;
                ls.push_back(y);
            }
        }

        reverse(ls.begin(),ls.end());
        ll pref=0;
        ll z=0;

        for(int c=0;c<ls.size();c++){
            pref+=ls[c];
            if(pref<0){
                z=c+1;
                pref=0;
            }
        }
        if(z==ls.size())continue;
        vector<ll> act1;
        act1.push_back(ls.back());
        for(int c=ls.size()-2;c>=z;c--){
            if(ls[c]/abs(ls[c])!=act1.back()/abs(act1.back())){
                act1.push_back(ls[c]);
            } else {
                act1.back()+=ls[c];
            }   
        }
        vector<vector<ll>> res;
        pref=0;
        ll delta=0;
        ll ng=0;
        ll pp=0;
        ll mc=0;
        // dbga(act1,act1.size());
        for(int c=0;c<act1.size();c+=2){
            pp+=act1[c+1];
            ng+=act1[c];
            mc=max(mc,delta-act1[c]);
            // dbgv(pp);
            // dbgv(ng);
            if(pp>ng){
                res.push_back({mc,pp+ng,(ll)lss.size()});
                delta=0;
                pp=0;
                ng=0;
                mc=0;
            } else {
                delta+=(act1[c+1]+act1[c]);
            }
        }
        lss.push_back(res);
    }

    // dbgv(lss.size());
    // for(int i=0;i<lss.size();i++){
    //     forn(j,lss[i].size()){
    //         cout<<lss[i][j][0]<<' '<<lss[i][j][1]<<' '<<lss[i][j][2]<<endl;
    //     }
    // }
    // cout<<"here"<<endl;
    priority_queue<vector<ll>,vector<vector<ll>>,greater<vector<ll>>> pq;
    map<int,int> done;
    for(int i=0;i<lss.size();i++){
        done[i]++;
        pq.push(lss[i][0]);
    }

    while(!pq.empty()){
        vector<ll>res=pq.top();
        pq.pop();
        if(x<res[0]){
            break;
        } else {
            
            x+=res[1];
            // dbgv(res[2]);
            if(done[res[2]]!=lss[res[2]].size()){
                // dbgv(done[res[2]]);
                pq.push(lss[res[2]][done[res[2]]]);
            }
            done[res[2]]++;
        }
    }

    cout<<x<<endl;


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
