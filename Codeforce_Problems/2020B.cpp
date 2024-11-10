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
#include <cmath>
#include <numeric>
map<ll,ll> dic;

void solve(){
    ll k;
    cin>>k;
    ll j=1;
    ll s=(ll)(floor)(sqrt(k));
    while(((s+j)*(s+j))-(s+j)<= k){
        s+=j;
        j*=2;
    }
    // dbgv(j);
    // dbgv(s);
    while(((s+j)*(s+j))-(s+j)<= k && j>0){
        cout<<"Here"<<endl;
        s+=j;
        j/=2;
    }
    ll p=0;
    for(ll step=s;step>=1;step/=2){
        while(s*s-s+(p+step)<=k)p+=step;
    }
    // dbgv(j);
    // dbgv(s);
    // dbgv(p);
    if(p==0){
        cout<<s*s-1<<endl;
    }
    else {
        cout<<s*s+p<<endl;
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
