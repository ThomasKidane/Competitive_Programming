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
    ll b[n];
    int c=0;
    ll w=0;
    ll extradel=INFINITY;
    int c00=0;
    int nn=0;
    forn(i,n){
        cin>>a[i];
    }
    
    forn(i,n){
        cin>>b[i];
        
    }
    forn(i,n){
        if(a[i]<b[i]){
            c++;
            w=max(w,b[i]-a[i]);
        } else {
            extradel=min(extradel,min(a[i]-b[i],a[i]));
        }
    }
    // dbgv(extradel);
    

    if(c>=2 || (extradel<w && c>0)){
        cout<<"NO"<<endl;
    } else{
        cout<<"YES"<<endl;
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
