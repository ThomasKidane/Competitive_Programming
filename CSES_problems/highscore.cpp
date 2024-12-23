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

bool dfsMT(int i, int j,bool connected[], map<int,vector<int>> &rev,bool vis[]){
    bool any=false;
    cout<<"here"<<endl;
    dbgv(j);
    vis[j]=true;
    if(j==0) {connected[j]=true;return true;}
    for(int k:rev[j]){
        if(k!=i && !vis[k]){
            dbgv(k);
            connected[j]|=dfsMT(j,k,connected,rev,vis);
            any|=connected[j];
        }
    }
    return false;
}

void solve()
{

    int n,m;
    cin>>n>>m;
    vector<ll> d(n, LLONG_MAX/12);
    map<int,vector<pair<int,ll>>> adj;
    map<int,vector<int>> rev;
    forn(i,m){
        int a,b;
        ll c;
        cin>>a>>b>>c;
        // if(a!=b){
            a--;
            b--;
            adj[a].push_back(make_pair(b,-c));
        // }
        rev[b].push_back(a);        
    }    

    bool connected[n]={false};
    bool visited[n];
    connected[n-1]=true;
    dfsMT(-1,n-1,connected,rev,visited);
    int cc=0;
    // for(auto it=adj.begin();it!=adj.end())
    for(int i=0;i<n;i++){
        if(!connected[i]){
            adj.erase(i);
        } else {
            cc++;
        }
    }
    
    d[0] = 0;
    cout<<"Start";
    forn(i,n){
        if(connected[i]){
            cout<<1<<' ';
        } else {
            cout<<0 <<' ';
        }
        cout<<endl;
    }
    if(!connected[0]){
        cout<<-1<<endl;
        return;
    }
    bool bec=false;
    int c=0;
    // dbgv(cc);
    
    for (;;) {
        bool any = false;

        for(auto it=adj.begin();it!=adj.end();it++){
        if(connected[it->ff]){
              for (auto pp : it->ss){
                if (d[it->first] <LLONG_MAX/12 && connected[pp.ff]){
                    if (d[pp.ff] > d[it->first] + pp.ss) {
                        d[pp.ff] = d[it->first] + pp.ss;
                        // if()
                        any = true;
                    }
                }
                       
            }
        }
      
            
        }
        
        c++;
        // dbgv(c);
        if (!any || c==cc-1){
            if(c==cc){
                bec=true;
            }
            break;
        }
            
    }

    if(bec){
        cout<<-1<<endl;
    } else {
        cout<<-d[n-1]<<endl;
    }
    // display d, for example, on the screen
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
