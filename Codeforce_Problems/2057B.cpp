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
    map<ll,ll> vals;
    forn(i,n){
        ll d;
        cin>>d;
        vals[d]++;
    }
    vector<ll> vv;
    for(auto it=vals.begin();it!=vals.end();it++){
        vv.push_back((it->ss));
    }
    sort(vv.begin(),vv.end());
    ll c=0;
    for(int i=0;i<vv.size();i++){
        if(vv[i]<=k){
            k-=vv[i];
            // vv.pop_front();
            c=i+1;
        } else {
            break;
        }
    }   
    if(n==0){
        cout<<0<<endl;
        return;
    }
    if(c==n-1){
        cout<<1<<endl;
        return;
    }
    cout<<max((ll)vv.size()-c,(ll)1)<<endl;
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
