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
    ll a[n];
    int e=0;
    int o=0;
    forn(i,n){
        cin>>a[i];
        (a[i]%2==1?o++:e++);
    }
    if(o>=1 && e>=1){
        cout<<o+1<<endl;
    } else if(o==0&&e>0){
        cout<<1<<endl;
    } else if(e==0 && o>1){
        cout<<o-1<<endl;
    } else {
        cout<<0<<endl;
    }
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
