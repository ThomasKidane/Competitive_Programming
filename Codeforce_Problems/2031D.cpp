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
    int n;
    cin>>n;
    int a[n];
    forn(i,n){
        cin>>a[i];
    }

    int premax[n];
    premax[0]=a[0];
    forn(i,n-1){
        premax[i+1]=max(premax[i],a[i+1]);
    }
    int minarray[n];
    bool blocked[n];
    minarray[n-1]=a[n-1];
    blocked[n-1]=false;    
    for(int i=n-2;i>=0;i--){
        minarray[i]=min(minarray[i+1],a[i]);
        // blocked[i]=(minarray[i+1]!=a[i]);
    }
    int maxx=0;
    int maxi=0;
    forn(i,n){
        // Binary search
        int v=i;
        
        maxi=max(i,maxi);
        v=maxi;
        maxx=max(premax[maxi],maxx);
        // if(!blocked[i]){
            for(int step=(n+1)/2;step>0;step/=2){
                // if(v+step<=n-1){
                    while(max(premax[v],maxx)>minarray[v+step] && v+step<=n-1){v+=step;step*=2;}
                // }
            }
        // }
        maxi=max(v,maxi);
        maxx=max(premax[v],maxx);
        
        cout<<premax[v]<<' ';
    }
    cout<<endl;
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
