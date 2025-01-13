#include<bits/stdc++.h>

using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second
#define int ll

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
    int c=0;
    forn(i,n){
        if(i==0){
            // cout<<0<<endl;
        }else{
            int j=upper_bound(a,a+n,a[i]/2)-a;

            // cout<<j<<endl;

            c+=j;

        }
    }

    cout<<c<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
