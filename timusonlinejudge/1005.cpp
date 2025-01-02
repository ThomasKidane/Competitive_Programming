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
    int w[n];
    int W=0;
    forn(i,n){
        cin>>w[i];
        W+=w[i];
    }
    int m=W;
    for(int i=0;i<(1<<n);i++){
        int s=0;
        for(int j=0;j<n;j++){
            if((i>>j)&1){
                s+=w[j];
            }
            m=min(m,max(W-s,s)-min(W-s,s));
        }
    }
    cout<<m;
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
