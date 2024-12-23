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
    int n,k;
    cin>>n;
    int s[n+1];
    map<int,vector<int>> adj;
    forn(i,n){
        cin>>s[i+1];
        if(s[i+1]==0){
            adj[0].push_back(i+1);
        }
        forn(i,s[i]){
            int a;
            cin>>a;
            adj[a].push_back(i+1);   
        }
    }

    int c=0;
    bool change=true;
    int cc=0;
    do {
        change=false;
        
    }
    while(change && c<n)
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
