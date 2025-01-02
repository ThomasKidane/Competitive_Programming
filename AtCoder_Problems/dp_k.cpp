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
    cin>>n>>k;
    int a[n];
    forn(i,n){
        cin>>a[i];
    }
    bool dp[k+1];
    dp[0]=false;
    for(int i=1;i<=k;i++){
        bool res=false;
        for(int j=0;j<n;j++){
            
            if(a[j]<=i){
                res|=(!dp[i-a[j]]);
            }
        }
        dp[i]=res;
    }
    if(dp[k]){
        cout<<"First";
    } else {
        cout<<"Second";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    // cin >>  T;
    while(T--){
        solve();
    }
    return 0;
}
