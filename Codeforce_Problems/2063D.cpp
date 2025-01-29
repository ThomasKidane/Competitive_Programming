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
    int n,m;
    cin>>n>>m;
    vector<int> a;
    vector<int> b;
    forn(i,n){
        int d;
        cin>>d;
        a.push_back(d);
        // cin>>a[i];
    }
    forn(i,m){
        int d;
        cin>>d;
        b.push_back(d);

        // cin>>b[i];
    }

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    if(n>m){
        swap(a,b);
        swap(n,m);
    }

    int res=min((n+m)/3,min(n,m));
    vector<ll> ansa((n)/2+1);
    vector<ll> ansb(m/2+1);
    ansa[0]=0;
    ansb[0]=0;
    forn(i,n/2){
        ansa[i+1]=ansa[i]+a[n-i-1]-a[i];
    }
    forn(i,m/2){
        ansb[i+1]=ansb[i]+b[n-i-1]+b[i];
    }
    
    dbga(ansa,n/2);
    dbga(ansb,m/2);
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
