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

int n, l;
vector<vector<int>> adj;

int timer;
vector<int> tin, tout;
vector<vector<int>> up;

void dfs(int v, int p)
{
    ::tin[v] = ++(::timer);
    ::up[v][0] = p;
    for (int i = 1; i <= ::l; ++i)
        ::up[v][i] = ::up[::up[v][i-1]][i-1];

    for (int u : ::adj[v]) {
        if (u != p)
            dfs(u, v);
    }

    ::tout[v] = ++::timer;
}

bool is_ancestor(int u, int v)
{
    return ::tin[u] <= ::tin[v] && ::tout[u] >= ::tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = ::l; i >= 0; --i) {
        if (!is_ancestor(::up[u][i], v))
            u = ::up[u][i];
    }
    return ::up[u][0];
}

void preprocess(int root) {
    ::tin.resize(::n);
    ::tout.resize(::n);
    ::timer = 0;
    ::l = ceil(log2(::n));
    ::up.clear();
    ::up.assign(::n, vector<int>(::l + 1));
    dfs(root, root);
}


void solve(){
    // int n;
    cin>>::n;
    // l=ceil(log2(n));
    vector<pair<int,int>> w;// weight and then val
    forn(i,::n){
        int d;
        cin>>d;
        w.push_back(make_pair(d,i)); 
    }
    ::adj.clear();
    ::adj.resize(::n);

    forn(i,n-1){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        ::adj[a].push_back(b);
        ::adj[b].push_back(a);
    }
    preprocess(0);

    sort(w.begin(),w.end());
    reverse(w.begin(),w.end());
    // forn(i,n){
    //     cout<<::tin[i]<<' '<<::tout[i]<<endl;
    // }
    int k=0;
    int bitch=w[0].ff;
    // cout<<k<<endl;
    while(k<n){
        if(w[k].ff==bitch){
            k++;
        } else{
            break;
        }
    }
    // dbgv(k);
    for(int i=k;i<n;i++){
        if(!is_ancestor(w[i].ss,w[i-1].ss)){
            cout<<w[i].ss+1<<endl;
            return;
        } 
    }
    
    // dbgv(adj.size());
    // dbgv(tin.size());
    // dbgv(up.size());
    cout<<0<<endl;


}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
