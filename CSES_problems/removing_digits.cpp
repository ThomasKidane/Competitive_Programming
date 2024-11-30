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
    int vals[n+1]={n+1};
    vals[0]=0;
    for(int i=1;i<=n;i++){
        int m=i;
        int v=i;
        while(v>0){
            if(v%10!=0){
                m=min(m,vals[i-v%10]+1);
            }
            
            // dbgv(i-v%10);
            // dbgv(v);
            v/=10;
            
        // dbgv(m);
        }
        vals[i]=m;
    }
    // dbga(vals,n);
    cout<<vals[n]<<endl;
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
