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
    int n,q;
    cin>>n>>q;
    map<ll,ll> dic;
    ll a[n];
    forn(i,n){
        cin>>a[i];
    }
    for(ll i=0;i<n;i++){
        if(i!=(n-1) && i!=0){
            dic[(i*(n-i)+(n-i-1))]++;
            // cout<<"First"<<endl;
            // dbgv((i*(n-1-i)+(n-i-1)));
            dic[(i+1)*(n-i-1)]+=(a[i+1]-a[i]-1);
            // cout<<"FSecond"<<endl;
            // dbgv(i);
            // dbgv((i+1)*(n-i-1));
            // dbgv((a[i+1]-a[i]-1));
            // dbgv(dic[5]);
        }
        else if(i!=(n-1)){
            dic[(i*(n-i)+(n-i-1))]++;
            // cout<<"AllF"<<endl;
            // dbgv((i*(n-1-i)+(n-i-1)));
            // cout<<"SAll"<<endl;
            dic[(i+1)*(n-i-1)]+=(a[i+1]-a[i]-1);
            // dbgv((i+1)*(n-i-1));
            // dbgv(a[i+1]-a[i]-1);
            // dbgv(dic[5]);
        } else {
            dic[n-1]++;
            // cout<<"Only"<<endl;
            // dbgv(n-1);
            // dbgv(dic[5]);
        }
    }
    forn(i,q){
        ll v;
        cin>>v;
        cout<<dic[v]<<' ';
    }
    cout<<endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
