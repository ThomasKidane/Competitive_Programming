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

int calc(int&i,int&e,vector<vector<int>>&adj,vector<int> &valmyself,vector<int>&mxval,vector<pair<pair<int,int>,int>>&maxxx){
    int c=0;
    if(e!=-1){
        c++;
    }
    valmyself[i]=adj[i].size();
    
    int m=0;
    int f=0;
    int s=0;
    bool done=true;
    vector<pair<int,int>> vals;
    for(int n:adj[i]){
        if(n!=e){
            vals.push_back(make_pair(calc(n,i,adj,valmyself,mxval,maxxx),n));
            m=max(vals.back().ff,m);

        }
    }
    // vals.push_back(make_pair(adj[i].size(),i));
    vals.push_back(make_pair(0,-1));
    vals.push_back(make_pair(0,-1));
    sort(vals.begin(),vals.end());
    reverse(vals.begin(),vals.end());
    maxxx[i].ff=vals.front();
    maxxx[i].ss=vals[1].ff;
    mxval[i]=m;
    // dbgv(valmyself[i]);

    // va=m;
    return max(m,valmyself[i]);
}

void calcdp(int&i,int&e,vector<vector<int>>&adj,vector<int>&valmyself,vector<int>&mxval,int twolevel,int f,int sc,int perp,int&m,vector<pair<pair<int,int>,int>>&maxxx){
    vector<pair<int,int>> tob;
    for(int n:adj[i]){
        if(n!=e){
            tob.push_back(make_pair(mxval[n],n));
            tob.push_back(make_pair(valmyself[n]-1,n));
        }
    }
    if(e!=-1){
        tob.push_back(make_pair(valmyself[e]-1,e));
    }
    
    // dbgv(valmyself[e]-1);
    tob.push_back(make_pair(f,-1));
    tob.push_back(make_pair(sc,-1));
    tob.push_back(make_pair(perp,-1));
    // dbgv(f);
    sort(tob.begin(),tob.end());
    reverse(tob.begin(),tob.end());
    for(auto pii:tob){
        // dbgv(pii.first-1+valmyself[i]);
        // dbgv(i);
        // dbgv(valmyself[i]);
        // dbgv(pii.first);
        m=max(m,pii.first-1+valmyself[i]);
    }
    tob.clear();
    vector<pair<int,int>> mxs=tob;
    // choose max of myself and valmyself
    for(int n:adj[i]){
        if(n!=e){
            mxs.push_back(make_pair(max(valmyself[n],mxval[n]),n));
        }
    }
    mxs.push_back(make_pair(0,-1));
    mxs.push_back(make_pair(0,-1));
    sort(mxs.begin(),mxs.end());
    reverse(mxs.begin(),mxs.end());

    for(int n:adj[i]){
        if(n!=e){
            if(n==maxxx[i].ff.ss){
                calcdp(n,i,adj,valmyself,mxval,valmyself[i],twolevel,maxxx[i].ss,max(perp,maxxx[i].ss),m,maxxx);
            } else {
                calcdp(n,i,adj,valmyself,mxval,valmyself[i],twolevel,maxxx[i].ff.ff,max(maxxx[i].ff.ff,perp),m,maxxx);
            }
        }
    }
}

void solve(){
    int n;
    cin>>n;
    vector<int> mxval(n,0);
    vector<vector<int>> adj(n,vector<int>(0));
    // map<int,vector<int>> vals;
    vector<int> valmyself(n,0);
    vector<pair<pair<int,int>,int>> maxxx(n);
    forn(i,n-1){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int m=0;
    int c=0;
    int b=0;
    int nn=-1;
    calc(c,nn,adj,valmyself,mxval,maxxx);
    calcdp(b,nn,adj,valmyself,mxval,0,0,0,0,m,maxxx);
    // forn(i,n){
    //     cout<<maxxx[i].ff.ff<<endl;
    // }
    // cout<<endl;
    cout<<m<<endl;

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
