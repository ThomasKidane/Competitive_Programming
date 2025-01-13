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
    int n,d;
    cin>>n>>d;
    vector<pair<int,int>> weights;
    forn(i,n){
        int t,l;
        cin>>t>>l;
        weights.push_back(make_pair(t,l));
    }

    for(int j=1;j<=d;j++){
        int m=0;
        for(int i=0;i<n;i++){
            m=max(m,weights[i].ff*(weights[i].ss+j));
        }
        cout<<m<<endl;
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
