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
    int n,x;
    cin>>n>>x;
    int a[n];
    map<int,int> dc;
    forn(i,n){
        cin>>a[i];
        if(a[i]<=n){
            dc[a[i]]++;
        }
    }
    int v[n];
    for(int i=0;i<=n;i++){
        if(dc[i]==0 && i<x){
            cout<<i<<endl;
            return;
        } else if(dc[i]==0 && v[i-x]>1){
            dc[i]++;
            v[i]=v[i-x]-1;
        } else if(dc[i]==0){
            cout<<i<<endl;
            return;
        } else if(i<x){
            v[i]=dc[i];
        } else {
            v[i]=v[i-x]+dc[i]-1;
        }
    }
    cout<<n+1<<endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
