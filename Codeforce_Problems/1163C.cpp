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
    ll n;
    cin>>n;
    // negative numerator
    vector<pair<ll,ll>> ps;
    forn(i,n){
        ll x,y;
        cin>>x>>y;
        ps.push_back(make_pair(x,y));

    }
    map<int,map<int,int>> slopes;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            ll t=(ps[i].ss-ps[j].ss); 
            ll b=(ps[i].ff-ps[j].ff);
            ll g=gcd(abs(t),abs(b));
            if((t)/abs(t)!=b/abs(b)){
                slopes[-abs(t)/g][abs(b)/g]++;
            } else {
                slopes[abs(t)/g][abs(b)/g]++;
            }
        }
    }

    ll c=0;
    for(auto it=slopes.begin();it!=slopes.end();it++){
        for(auto it1=it->ss.begin();it1!=it->ss.end();it1++){
            c++;
        }
    }
    ll v=0;
    for(auto it=slopes.begin();it!=slopes.end();it++){
        for(auto it1=it->ss.begin();it1!=it->ss.end();it1++){
            c++;
        }
    }
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
