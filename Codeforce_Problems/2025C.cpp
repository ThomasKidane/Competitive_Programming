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
    ll n,k;
    cin>>n>>k;
    map<ll,ll> dc;
    forn(i,n){
        ll d;
        cin>>d;
        dc[d]++;
    }

    ll m=0;
    ll curl=0;
    ll las=0;
    ll S=0;
    ll len=0;
    deque<ll> col;
    for(auto it=dc.begin();it!=dc.end();it++){
        if(it->first-las!=1){
            col.clear();
            col.push_back(it->second);
            S=it->second;
            len=1;
            m=max(S,m);
            las=it->first;
            
        } else if(it->first-las==1){
            if(len<k){
                S+=it->second;
                len++;
                m=max(S,m);
                las=it->first;
                col.push_back(it->second);
            } else {
                ll b=col.front();
                S-=b;
                col.pop_front();
                S+=it->second;
                col.push_back(it->second);
                // len++;
                m=max(S,m);
                las=it->first;                
            }
        }
    }

    cout<<m<<endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
