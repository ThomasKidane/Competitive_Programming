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

pair<ll,ll> range(int n,ll k,ll ll2,ll r2){
    ll val=1;
    for(int i=0;i<n;i++){
        val*=k;
    }
    if((ll2/n)*n>=ll2){
        return make_pair(ll2/n+1,r2/n);
    } else {
        return make_pair(ll2/n,r2/n);
    }
    // return make_pair()
}

void solve(){
    ll k,l1,r1,l2,r2;
    cin>>k>>l1>>r1>>l2>>r2;
    ll val=1;
    vector<pair<ll,ll>> ranges;
    for(int n=0;n<31;n++){
        // dbgv(l2);
        if(val*k<=val || (val*k)/k!=val || (r2/(val))==0){
            break;
        } else {
            
            ranges.push_back(range(n,k,l2,r2));
            val*=k;
        }
    }

    ll c=0;
    ll l=l1;
    ll r=l1;
    sort(ranges.begin(),ranges.end());
    dbgv(ranges.size());
    int m=0;
    for(int i=0;i<ranges.size();i++){
        cout<<ranges[i].ff<<' '<<ranges[i].ss<<endl;
    }
    for(int i=0;i<ranges.size();i++){
        dbgv(ranges[i].ff);
        if(ranges[i].ss>=l){
            cout<<"Here"<<endl;
            dbgv(min(r2,min(r1,ranges[i].ss)));
            dbgv(l);
            if(min(r2,min(r1,ranges[i].ss))>=l){
                
                m+=min(r2,min(r1,ranges[i].ss))-l+1;
            }
            // dbgv(c);
            // c+=-l+1;
            l+=m;
            c+=m;
            m=0;
            // c=0;
        }
    }

    cout<<c<<endl;

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
