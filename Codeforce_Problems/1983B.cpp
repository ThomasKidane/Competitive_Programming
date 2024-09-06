#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define forn(i,n) for(int i=0;i<n;i++)
#define dbgv(v) cout<<#v<<" "<<v<<'\n';
#define dbga(a,n) forn(i,n-1) {cout<<a[i]<<' ';} cout<<a[n-1]<<'\n';

signed main(){
    int t,n,m;cin>>t;
    while(t--){
        cin>>n>>m;
        string s;
        int a[n][m];
        int b[n][m];
        int aw[n]={0},bw[n]={0},ah[m]={0},bh[m]={0};
        forn(i,n){
            cin>>s;
            forn(j,m){
            a[i][j]=int(s[j])-48;
            aw[i]=(aw[i]+a[i][j])%3;
            ah[j]=(ah[j]+a[i][j])%3;
        }}
        forn(i,n){
            cin>>s;
            forn(j,m){
            b[i][j]=int(s[j])-48;
            bw[i]=(bw[i]+b[i][j])%3;
            bh[j]=(bh[j]+b[i][j])%3;
        }}
        bool done=false;
        forn(i,n){
            if(aw[i]!=bw[i]){cout<<"NO\n";done=true;break;}
        }
        if(done) continue;
        forn(i,m){
            if(ah[i]!=bh[i]){cout<<"NO\n";done=true;break;}
        }
        if(done) continue;
        else cout<<"YES\n";

    }


}


