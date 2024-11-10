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
    ll S=0;
    ll a[n];
    forn(i,n){
        cin>>a[i];
        S+=a[i];
    }
    ll M=S;
    for(int i=0;i<(1<<n);i++){
        ll m=0;
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                m+=a[j];
            }
        }
        // dbgv(m);
        M=min(M,abs(abs(S-m)-m));
    }
    cout<<M;

}

int main() {
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
