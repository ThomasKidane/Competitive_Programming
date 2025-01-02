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

void dfs(int p,int c,ll &res,pair<ll,ll> info,vector<int>&nonnl,vector<bool>&leaf,vector<bool>&nl,map<int,vector<int>>&adj){
    // if(!leaf[c] && )
    if(p!=-1){
        if(!leaf[c] && !nl[p] && !leaf[p]){
            res+=info.ff;
        }
    }

    ll s=0;
    for(int n:adj[c]){
        if(n!=p){
            // if(!leaf[n]&&!nl[n]){
                // non
            // }
            s+=nonnl[n];
        }
    }
    for(int n:adj[c]){
        if(n!=p){
            if(!leaf[n]&&!nl[n]){
                res+=nonnl[n];
            }
            dfs(c,n,res,make_pair(info.ff+s-nonnl[n]+(!nl[c]&&!leaf[c]),c),nonnl,leaf,nl,adj);

            // s+=nonnl[n];
        }
    }
}

int nnn(int p,int c,vector<int>&nonnl,vector<bool>&leaf,vector<bool>&nl,map<int,vector<int>>&adj){
    int s=(!leaf[c] && !nl[c]);
    for(int n:adj[c]){
        if(n!=p){
            s+=nnn(c,n,nonnl,leaf,nl,adj);
        }
    }

    nonnl[c]=s;
    return s;
}
void solve(){
    int n;
    cin>>n;
    map<int,vector<int>> adj;
    
    forn(i,n-1){
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(n==2){
        cout<<0<<endl;
        return;
    }
    int l=0;
    vector<bool> leaf(n,false);
    forn(i,n){
        if(adj[i].size()==1){
            l++;
            leaf[i]=true;
        }
    }

    vector<bool> nl(n,false);
    forn(i,n){
        if(leaf[i]){
            nl[adj[i].back()]=true;
        }
    }

    int nll=0;
    forn(i,n){
        if(nl[i] && !leaf[i]){
            nll++;
        }
    }

    // dbgv((n-nll-l));
    vector<int> nonnl(n,0);
    ll res=0;
    nnn(-1,0,nonnl,leaf,nl,adj);
    
    dfs(-1,0,res,make_pair(0,-1),nonnl,leaf,nl,adj);
    cout<<(ll)n*(n-1)-(ll)l*(l-1)-((ll)l*(n-l)+(ll)nll*(n-l-1))-res<<endl;




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
