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

ll dist(ll xs,ll ys,ll xt,ll yt){
    return (xs-xt)*(xs-xt)+(ys-yt)*(ys-yt);
}

void solve(){
    int n;
    cin>>n;
    ll xss[n];
    ll yss[n];
    ll xs,ys,xt,yt,d;
    forn(i,n){
        cin>>d;
        xss[i]=d;
        cin>>d;
        yss[i]=d;
    }
    cin>>xs>>ys>>xt>>yt;
    bool flag=true;
    forn(i,n){
        if(dist(xss[i],yss[i],xt,yt)<=dist(xs,ys,xt,yt)){
            flag=false;
            break;
        }
    }
    if(flag){cout<<"YES"<<endl;}
    else cout<<"NO"<<endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
