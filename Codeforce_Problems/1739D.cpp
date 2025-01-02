#include <bits/stdc++.h>

using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

#define forn(i,n) for(int i=0;i<n;i++)
#define dbgv(v) cout<<#v<<" "<<v<<endl
#define dbga(a,n) forn(i,n-1) {cout<<a[i]<<' ';} cout<<a[n-1]<<'\n';

int counter(int e,int c,map<int,vector<int>>&adj,int h,int l){
    int cc=0;
    for(int i:adj[c]){
        if(i!=e){
            if(h+1>l){
                cc++;
                cc+=counter(c,i,adj,1,l);
            } else {
                cc+=counter(c,i,adj,h+1,l);
            }
        }
    }

    return cc;
}

void solve(){
    int n,k;
    cin>>n>>k;
    map<int,vector<int>> adj;
    for(int i=2;i<=n;i++){
        int d;
        cin>>d;
        adj[d].push_back(i);
        adj[i].push_back(d);
    }
    // cout<<"her"<<endl;

    int h=n-1;
    bool twice=false;
    for(int step=(n+1)/2;step>=0;step/=2){
        if(step==0){
                if(twice){
                    break;
                } else {
                    twice=true;
                }
            }
        if(h-step>0){
            int c=0;
            while(counter(-1,1,adj,0,h-step)<=k){
                h-=step;
                if(h-step<=0){
                    break;
                }
                // break;
                c++;
                if(c>3){
                    break;
                }
            }

        }
    }

    cout<<h<<endl;

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
