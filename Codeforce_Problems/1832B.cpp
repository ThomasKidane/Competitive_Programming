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
    deque<ll> a;
    ll ss=0;
    vector<ll> pref(n+1);
    forn(i,n){
        ll d;
        cin>>d;
        a.push_back(d);
        // ss+=d;
    }
    sort(a.begin(),a.end());
    // reverse(a.begin(),a.end());
    pref[0]=0;
    forn(i,n){
        // ll d;
        // cin>>d;
        // a.push_back(d);
        ss+=a[i];
        pref[i+1]=pref[i]+a[i];
    }
    
    
    // 
    // dbga(a,a.size());
    ll s=pref[2*k];
    ll v=0;
    for(int i=2*k-2;i>=0;i-=2){
        s=min(pref[i]+a.back()+v,s);
        v+=a.back();
        a.pop_back();
    }
    

    cout<<ss-s<<endl;
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
