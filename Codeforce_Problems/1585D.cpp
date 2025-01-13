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

bool comp(pair<int,int> p1,pair<int,int> p2){
    return p1.ss<p2.ss;
}

int dfs(vector<pair<int,int>> &v,int i,vector<bool> &vs){
    vs[i]=true;
    if(!vs[v[i].ff] && v[i].ff!=i){
        return dfs(v,v[i].ff,vs)+1;
    } else {
        return 0;
    }
}

void solve(){
    int n;
    cin>>n;
    map<int,int> dns;
    bool done=false;
    vector<pair<int,int>> v;
    forn(i,n){
        int d;
        cin>>d;
        v.push_back(make_pair(d,i));
        dns[d]++;
        if(dns[d]>1){
            done=true;
        }
    }
    if(done==true || n==1){
        cout<<"YES"<<endl;
    } else if(n==2){
        cout<<(v[0].ff>v[1].ff ? "NO": "YES")<<endl;
    } else {
        sort(v.begin(),v.end());
        forn(i,n){
            v[i].ff=i;
        }
        sort(v.begin(),v.end(),comp);
        vector<bool> vis(n);
        int c=0;
        forn(i,n){
            if(!vis[i] && v[i].ff!=v[i].ss){
                c+=dfs(v,i,vis);
            }
        }
        // dbgv(c);
        if(c%2==0){
            cout<<"YES"<<endl;
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
