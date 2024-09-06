#include<bits/stdc++.h>

using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define sscond

#define forn(i,n) for(int i=0;i<n;i++)
#define dbgv(v) cout<<#v<<" "<<v<<endl
#define dbga(a,n) forn(i,n-1) {cout<<a[i]<<' ';} cout<<a[n-1]<<'\n';

ll mex(vector<ll> &a) {
    vector<bool> f(a.size() + 1, 0);
    for (int i : a) if (i <= (ll) a.size()) f[i] = 1;
    ll mex = 0;
    while (f[mex]) ++mex;
    return mex;
}

void solve(){
    ll n,m,l,d;
    cin>>n>>m;
    ll Max=0;
    forn(i,n){
        cin>>l;
        vector<ll> used;
        forn(j,l){
            cin>>d;
            used.push_back(d);
        }
        Max=max(mex(used),Max);
        used.push_back(mex(used));
        Max=max(mex(used),Max);
    }
    ll S=0;
    S+=min(m,Max)*Max+Max;
    if(m>Max){
        S+=(ll)((ld)((Max+1)+m)/(ld)2*(ld)(m-Max));
    }
    cout<<S<<endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
