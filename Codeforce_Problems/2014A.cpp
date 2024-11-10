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
    int g[n];
    forn(i,n)cin>>g[i];
    int c=0;
    int v=0;
    forn(i,n){
        if(g[i]>=k){
            v+=g[i];
        } else if(g[i]==0 && v>0){
            c++;
            v--;
        }
    }

    cout<<c<<endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
