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
    int N=20;
    int C[N][N];
    for (int n = 0; n < N; n++) { // loop over n from 0 to N-1 (inclusive)
        C[n][0] = 1;
        C[n][n] = 1;
        for (int k = 1; k < n; k++) // loop over k from 1 to n-1 (inclusive)
            C[n][k] = C[n][k - 1] + C[n - 1][k - 1];
    }
    // for(int i=0;i<N;i++){
    //     for(int j=0;j<=i;j++){
    //         cout<<C[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }

    // for(int i=0;i<N;i++){
    //     for(int j=0;j<=i;j++){
    //         cout<<C[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }

    // }

    vector<ll> ans(100002);
    ll start=1;
    // ll v=0;
    for(int i=0;i<100002;i++){
        ans[i]=start;
        start=start*2;
        // start%=(37);
        start=start%(ll)(1e9+7);
        // if(start==0){
        //     v=i;
        //     // cout<<"NEver"<<endl;
        //     break;
        // }
    }
    // dbgv(v);
    // cout<<"Here"<<endl;
    // dbga(ans,N);
    // cout<<endl;
    // cout<<ans[99999]<<endl;

    // cout<<(ll)(1e9+7)<<endl;

    int tt;
    cin>>tt;
    // cout<<"Here"<<endl;
    ll n[tt],k[tt];
    for(int i=0;i<tt;i++){
        cin>>n[i];
    }
    for(int i=0;i<tt;i++){
        cin>>k[i];
    }
    for(int i=0;i<tt;i++){
        // if(k[i]==n[i]-1){
        //     cout<<1<<endl;
        // } else {
            cout<<ans[k[i]]<<endl;
        // }
    }
}

int main() {
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
