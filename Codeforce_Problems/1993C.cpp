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
    ll a[n];
    forn(i,n)cin>>a[i];
    bool flag=true;
    map<int,int> divs;//xmodk  & parity
    ll l=2*n,r=-1;
    ll M=a[0];
    forn(i,n){
        //cout<<divs[a[i]%k]<<endl;
        if(divs[a[i]%(2*k)]==0){
            divs[a[i]%(2*k)]=(((a[i])/(2*k))%2==0) ? 2 : 1;
            l=min(a[i]%(2*k),l);
            r=max(a[i]%(2*k),r);
            M=max(a[i],M);
        } else {
            if(divs[a[i]%k]!=((((a[i])/k)%2==0) ? 2 : 1)) {
                flag=false;break;
            }
        }
    }
    dbgv(l);
    dbgv(r);
    if(!flag || (r>=(l+k)&&(r+k)%(2*k)<=l)) {cout<<-1<<endl;}
    else {
        cout<<(M/(2*k))*(2*k)+min(l%k,r%k)<<endl;
    }
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
