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
    map<ll,ll> vals;
    // ll mi=2e9;
    ll mx=-2e9;
    forn(i,n){
        ll x;
        cin>>x;
        vals[x]++;
        vals[x+1]--;
    }
    int c=0;
    ll l=-2e9;
    bool inrange=true;
    priority_queue<vector<long long>,vector<vector<ll>>,greater<vector<long long>>> pq;//min cost and what is position, and what is left in range and bit(0,minus,1, means plus)
    // vector<ll> mm;
    
    int cc=0;
    for(auto it=vals.begin();it!=vals.end();it++){   
        // cout<<"her"<<endl;
        // dbgv(mx);     
        mx=it->ff;
        if(inrange){
            ll nx=it->ff;
            if((nx-l)>1){
                // dbgv(nx);
                // dbgv(l);
                vector<ll> mm1;
                vector<ll> mm2;
                mm1.push_back(1);
                mm1.push_back(nx-1);
                mm1.push_back(l+(nx-l+1)/2);
                mm1.push_back(0);
                if(cc!=0){
                    mm2.push_back(1);
                mm2.push_back(l);
                mm2.push_back(l+(nx-l+1)/2-1);
                mm2.push_back(1);
                pq.push(mm2);
                }
                
                pq.push(mm1);
                
            } else {


                    vector<ll> mm1;
                    // vector<ll> mm2;
                    mm1.push_back(1);
                    mm1.push_back(nx-1);
                    mm1.push_back(nx-1);
                    mm1.push_back(0);
                    // mm2.push_back(1);
                    // mm2.push_back(l+1);
                    // mm2.push_back(l+(nx-l+1)/2);
                    // mm2.push_back(1);
                    pq.push(mm1);
                    // pq.push(mm2);
                
            }
        }
        cc++;
        c+=it->ss;
        if(c==0){
            l=it->ff;
            inrange=true;
        } else {
            inrange=false;
        }
    }
    vector<ll>mxx;
    mxx.push_back(1);
    mxx.push_back(mx);
    mxx.push_back((ll)2e9);
    mxx.push_back(1);
    pq.push(mxx);
    ll cost=0;
    vector<int>pos;
    forn(i,m){
        // cout<<"here"<<endl;
        vector<ll>mm=pq.top();
        pq.pop();
        cost+=(mm.front());      
        pos.push_back(mm[1]);
    //    dbga(mm,4);

        if(mm[3]){
            mm[1]++;
            if(mm[1]>mm[2]){
                continue;
            } else {
                mm[0]++;
                pq.push(mm);
            }
        } else {
            mm[1]--;
            if(mm[1]<mm[2]){
                continue;
            } else {
                mm[0]++;
                pq.push(mm);
            }
        }
    }

    cout<<cost<<endl;
    forn(i,m){
        cout<<pos[i]<<' ';
    }
    cout<<endl;
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
