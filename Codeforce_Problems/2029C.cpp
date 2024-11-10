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

int val(int x,int a){
    if(x==a){
        return 0;
    } else if(x<a){
        return 1;
    } else {
        return -1;
    }
}

void solve(){
    int n;
    cin>>n;
    int a[n];
    forn(i,n){
        cin>>a[i];
    }
    int x=0;
    if(n==1){
        cout<<0<<endl;
        return;
    } else {
        vector<vector<int>> dp;
        dp.push_back({0,0,0,val(0,a[0])}); //
        for(int i=1;i<n;i++){
            vector<int> tb(4);
            tb[3]=dp.back().back()+val(dp.back().back(),a[i]);
            tb[0]=max(dp.back()[3],dp.back()[0]);
            tb[1]=max(dp.back()[0]+val(dp.back()[0],a[i]),dp.back()[1]+val(dp.back()[1],a[i]));
            tb[2]=max(dp.back()[0]+val(dp.back()[0],val(dp.back()[0],a[i])),dp.back()[2]+val(dp.back()[2],a[i]));
            dp.push_back(tb);
            // dbga(tb,4);
        }

        cout<<max(dp.back()[0],max(dp.back()[1],dp.back()[2]))<<endl;
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
