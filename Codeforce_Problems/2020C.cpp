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
    ll b,c,d;
    cin>>b>>c>>d;
    ll a=0;
    for(int i=0;i<=61;i++){
        int bw=(b>>i)%2;
        
        int cw=(c>>i)%2;
        int dw=(d>>i)%2;
        // dbgv(bw);
        // dbgv(cw);
        // dbgv(dw);
        if(dw==1){
            if(bw==0 && cw==0){
                a+=(1ll<<i);
            } else if(bw==1 && cw==0) {
                // a+=(1<<i);
            } else if(bw==0 && cw==1){
                cout<<-1<<endl;
                return;
            }
        } else {
            if(bw==1 && cw==0){
                cout<<-1<<endl;
                return;
            } else if(bw==1 && cw==1){
                a+=(1ll<<i);
            }
        }
    }
    cout<<a<<endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
