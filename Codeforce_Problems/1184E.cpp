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

int findp(int x,vector<int>&p){
    if(p[x]!=x){
        return findp(p[x],p);
    } else {
        return x;
    }
}

bool same(int x,int y,vector<int>&p){
    return findp(x,p)==findp(y,p);
}

void unite(int x,int y,vector<int>&sz,vector<int>&p){
    if(sz[findp(y,p)]>sz[findp(x,p)])swap(x,y);
    sz[findp(x,p)]+=sz[findp(y,p)];
    p[findp(y,p)]=p[findp(x,p)];
}

vector<vector<ll>> minimum_tree(vector<vector<ll>>&edges,vector<int>&p,vector<int>&sz){
    vector<vector<ll>>f;
    for(int i=0;i<edges.size();i++){
        if(!same(edges[i][1],edges[i][2],p)){
            unite(edges[i][1],edges[i][2],sz,p);
            f.push_back({edges[i][1],edges[i][2]});
        }
    }
    return f;
}

bool containtsf(int b1,int b2,vector<vector<ll>>&f){
    // int a=edges[0][1];
    // int b=edges[0][2];
    for(int i=0;i<f.size();i++){
        if(b1==f[i][0]&&b2==f[i][1]){
            return true;
        }
}
return false;
}


void solve(){
    int n,m;
    cin>>n>>m;
    // weight,a,b
    vector<vector<ll>> edges;
    forn(i,m){
        ll w,a,b;
        cin>>a>>b>>w;
        a--;
        b--;
        edges.push_back({w,a,b});
    }    

    int e1=edges[0][1];
    int e2=edges[0][2];
    ll w=1000000000;
    edges[0][0]=0;


    vector<int> p(n,0);
    forn(i,n){
        p[i]=i;
    }
    vector<int> sz(n,1);
    // sort(edges.begin(),edges.end());
    int b1=edges[0][1];
    int b2=edges[0][2];
    
    int mm=0;
    for(int step=(w)/2;step>0;(step==1?step=0:step=max(step/2,1))){
        if(mm+step>w)continue;
        p.clear();
        p=vector<int> (n,0);
        forn(i,n){
            p[i]=i;
        }
        sz.clear();
        sz=vector<int>(n,1);
        edges[0][0]=mm+step;
        vector<vector<ll>>other;
        forn(i,m){
            other.push_back(edges[i]);
        }

                stable_sort(other.begin(),other.end());
                // forn(i,m){
                //     dbga(other[i],3);
                // }

        vector<vector<ll>> f=minimum_tree(other,p,sz);
        while(containtsf(b1,b2,f)){
            mm+=step;
            if(mm+step>w)break;
            p.clear();
            p=vector<int> (n,0);
            forn(i,n){
                p[i]=i;
            }
            sz.clear();
            sz=vector<int>(n,1);
            edges[0][0]=mm+step;
            vector<vector<ll>>other;
            forn(i,m){
            other.push_back(edges[i]);
        }
                    stable_sort(other.begin(),other.end());

            f=minimum_tree(other,p,sz);
            if(!containtsf(b1,b2,f)){
                break;
            }
        }
    }
    cout<<mm<<endl;
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
