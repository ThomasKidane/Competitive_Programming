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
    int n,r;
    cin>>n>>r;
    int a[n];
    int s=0;
    int l=0;
    int v=0;
    forn(i,n){
        cin>>a[i];
        s+=a[i];
        v+=a[i]/2;
        l+=(a[i]%2);
    }
    cout<<s-2*max(0,l-(r-v))<<endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
