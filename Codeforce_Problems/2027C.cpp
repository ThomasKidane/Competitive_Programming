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

ll dfs(ll a,map<ll,vector<ll>>& buckets,vector<bool>& seen){
    ll m=a;
    if(buckets[a].size()==0)return a;
    forn(j,buckets[a].size()){
        if(!seen[buckets[a][j]]){
            seen[buckets[a][j]]=true;
            m=max(dfs(a+buckets[a][j],buckets,seen),m);
        }
    }

    return m;
}


void solve(){
    ll n;
    cin>>n;
    map<ll,vector<ll>> buckets;
    forn(i,n){
        ll d;
        cin>>d;
        buckets[i+d].push_back(i);
    }
    ll M=n;
    vector<bool> seen(n,false);
    forn(i,buckets[n].size()){
        if(!seen[buckets[n][i]]){
            seen[buckets[n][i]]=true;
            M=max(dfs(n+buckets[n][i],buckets,seen),M);
        }        
    }

    cout<<M<<endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
