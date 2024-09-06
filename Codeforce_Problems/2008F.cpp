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

ll getExp(ll a,ll b){
    ll res=1;
    forn(i,32){
        if(b&(1<<i)) {res*=a;res%=(1000000007);}
        a*=a;
        a%=(1000000007);
    }
    return res;
}

void getRes(ll S, ll c){
    if(S%c==0){cout<<((S/c)%(1000000007)+(1000000007))%(1000000007)<<endl;}
    else {
        cout<<(((S)*getExp(c,(1000000007)-2))%(1000000007)+(1000000007))%(1000000007)<<endl;
    }
}

void solve(){
    int n;
    cin>>n;
    ll a[n];
    forn(i,n)cin>>a[i];
    ll pref[n+1]={0};
    forn(i,n){
        pref[i+1]=pref[i]+a[i];
        pref[i+1]%=(1000000007);
    }
    ll S=0;
    int c=0;
    forn(i,n){
        S+=(pref[n]-pref[i+1])*a[i];
        S=(S)%(1000000007);
        c+=(n-i-1);
        c=c%(1000000007);
    }
    getRes(S,c);
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
