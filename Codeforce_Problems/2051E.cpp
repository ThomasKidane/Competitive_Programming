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

ll mxprofit(ll b[],ll p,int n){
    ll profit=0;
    int l=lower_bound(b,b+n,p)-b;
    if(b[l]<p)return 0;
    // dbgv(b[l]);
    return (n-l)*p;
}

void solve(){
    int n,k;
    cin>>n>>k;
    // int a[n]
    ll a[n];
    ll b[n];
    forn(i,n){
        cin>>a[i];
    }
    forn(i,n){
        cin>>b[i];
    }

    map<ll,int> vals;
    forn(i,n){
        vals[a[i]]++;
        vals[b[i]]--;
    }
    sort(a,a+n);
    ll mp=mxprofit(b,a[0],n);
    sort(b,b+n);
    // dbgv(mp);
    int s=0;
    for(auto it=vals.begin();it!=vals.end();it++){
        // dbgv(it->first);
        
        if(s<=k){
            // dbgv(s);
            // dbgv(it->first);
            mp=max(mp,mxprofit(b,it->first,n));
        }
        s+=it->second;
        
    }

    cout<<mp<<endl;
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
