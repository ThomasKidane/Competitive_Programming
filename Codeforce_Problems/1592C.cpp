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

pair<int,int> count(int i,int e,ll t,ll a[],map<int,vector<int>>&adj,vector<bool>& v){
    v[e]=true;
    ll res=a[e];
    int c=0;
    for(int n:adj[e]){
        if(!v[n]){
            pair<int,int> ress=count(e,n,res,a,adj,v);
            res^=ress.ff;
            c+=ress.ss;
        }
    }
    if(res==t)c++;
    return make_pair(res,c);
}

void solve(){
    int n,k;
    cin>>n>>k;
    ll a[n];
    ll res=0;
    forn(i,n){
        cin>>a[i];
        res^=a[i];
    }
    int cc=0;
    forn(i,n){
        if(res==a[i]){
            cc++;
        }
    }
    map<int,vector<int>> adj;
    forn(i,n-1){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<bool> vis(n,false);

    if(res==0){
        cout<<"YES"<<endl;
    } else {
        // cout<<"Here"<<endl;
        // dbgv(res);
        // dbgv(count(-1,0,res,a,adj,vis).ss);
        if(count(-1,0,res,a,adj,vis).ss>=3 || cc>1){
            cout<<"YES"<<endl;
            return;
        } else {
            cout<<"NO"<<endl;
        }
    }
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
