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
    int b[n];
    forn(i,n){
        cin>>a[i];
        
    }
    forn(i,n){
        cin>>b[i];
    }

    vector<pair<int,int>> paths;
    forn(i,n){
        paths.push_back(make_pair(a[i],b[i]));
    }
    ll res=-100000000000;
    forn(i,n){
        ll mx=(paths[i].ff+paths[i].ss);
        for(int j=0;j<n;j++){
            if(i!=j){
                mx+=max(paths[j].ff,paths[j].ss);
            }
            
        }

        res=max(mx,res);
    }

    cout<<res<<endl;
    
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
