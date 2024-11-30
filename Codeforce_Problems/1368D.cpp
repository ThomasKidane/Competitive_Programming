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

bool notempty(int a[],int n){
    forn(i,n){
        if(a[i]!=0){
            return true;
        }
    }

    return false;
}
void solve(){
   int n;
   cin>>n;
    int vals[n];
   forn(i,n){
        cin>>vals[i];
   } 
   int dp[21]={0};
   forn(i,n){
        forn(j,20){
            if((1<<j)&vals[i]){
                dp[j]++;
            }
        }
   }
   ll ans=0;
    while(notempty(dp,21)){
        ll v=0;
        forn(i,21){
            if(dp[i]>0){
                v|=(1<<i);
                dp[i]--;
            }
        }
        ans+=(v*v);
    }

    cout<<ans;
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
