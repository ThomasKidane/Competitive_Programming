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
    int n,x;
    cin>>n>>x;
    int c[n];
    for(int &d:c){
        cin>>d;
    }
    vector<ll> vals(x+1,INFINITY);
    vals[0]=0;
    forn(i,n){
        forn(j,x){
            if(j+c[i]<=x && vals[j]<=x+2){
                vals[j+c[i]]=min(vals[j]+1,vals[j+c[i]]);
            }
        }
    }
    if(vals[x]>=x+2){
        cout<<-1<<endl;
    } else {
        cout<<vals[x]<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
