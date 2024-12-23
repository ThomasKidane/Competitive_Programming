#include<bits/stdc++.h>

using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second
#define int ll
#define forn(i,n) for(int i=0;i<n;i++)
#define dbgv(v) cout<<#v<<" "<<v<<endl
#define dbga(a,n) forn(i,n-1) {cout<<a[i]<<' ';} cout<<a[n-1]<<'\n';
void solve(){
    int n,k;
    cin>>n>>k;
    // string s;
    // cin>>s;
    int a[n];
    for(int &d:a){
        cin>>d;
    }
    int prefS[n+1];
    prefS[n]=0;
    prefS[0]=0;
    for(int i=n-1;i>=0;i--){
        prefS[i]=prefS[i+1]+a[i];
        // if(s[i]=='1'){
        //     prefS[i]=prefS[i+1]+1;
        // } else {
        //     prefS[i]=prefS[i+1]-1;
        // }
    }

    ll ss=prefS[0];
    int p=0;
    
    sort(prefS+1,prefS+n);
    reverse(prefS+1,prefS+n);
    // dbga(prefS,n+1);
    for(int i=1;i<k;i++){
        ss+=prefS[i];
        // if(ss<k){
        //     if(prefS[i]>0){
        //         ss+=prefS[i];
        //         p++;
        //     }
        // }
    }
    // dbgv(ss);
    // if(ss>=k){
    //     cout<<p+1<<endl;
    // } else {
    //     cout<<-1<<endl;
    // }
    //                                  nmkm

    cout<<ss<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
