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
    int dp[n];
    dp[0]=1;
    int mm=0;
    for(int i=1;i<n;i++){
        int m=1;
        for(int j=0;j<i;j++){
            if(a[j]<a[i]){
                m=max(m,dp[j]+1);
            }
        }
        dp[i]=m;
        mm=max(mm,m);
    }
    mm=max(mm,dp[0]);
    cout<<mm<<endl;
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
