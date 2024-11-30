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
    ll m=100000000000;
    int f=0;
    forn(i,n){
        cin>>a[i];
        b[i]=a[i];
        m=min(m,a[i]);
    }
    forn(i,n){
        if(a[i]==m){
            f=i;
            break;
        }
    }
    sort(b+f,b+n);
    for(int i=f;i<n;i++){
        if(b[i]!=a[i]){
            cout<<-1<<endl;
            return;
        }
    }
    cout<<f<<endl;
    
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
