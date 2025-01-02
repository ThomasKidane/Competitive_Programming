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
    int n;
    cin>>n;
    ld ps[n];
    forn(i,n){
        cin>>ps[i];
    }
    vector<vector<ld>> vals;
    vals.push_back({1-ps[0],ps[0]});
    for(int i=1;i<n;i++){
        vector<ld> vv(i+2,0);
        //  forn(j,i){
        //     cout<<vals.back()[j]<<' ';
        // }
        // cout<<endl;
        for(int j=0;j<=i;j++){
            vv[j+1]+=vals.back()[j]*ps[i];
            vv[j]+=vals.back()[j]*(1-ps[i]);
        }
        vals.push_back(vv);
        // dbgv(i+1);
        
        // cout<<endl;
    }

    ld s=0;
    for(int i=(n+1)/2;i<=n;i++){
        s+=vals.back()[i];
    }
    cout<<setprecision(15)<<s<<endl;
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
