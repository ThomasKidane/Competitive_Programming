#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i,n) for(int i=0;i<n;i++)
#define dbgv(v) cout<<#v<<" "<<v<<'\n';
#define dbga(a,n) forn(i,n-1) {cout<<a[i]<<' ';} cout<<a[n-1]<<endl;

signed main(){
    int t,n,m,k;cin>>t;
    while(t--){
        cin>>n>>m>>k;
        string s;
        cin>>s;
        int w=0;
        int toS=0;
        bool flag=false;
        s="L"+s;
        forn(i,n+1){
        if(s[i]=='L'){
            forn(j,m){
            toS=j;
            if(s[i+j+1]=='L'){break;}
            }
            i=i+toS;
        } else if(s[i]=='C'){
            cout<<"NO"<<endl;
            flag=true;
            break;

        } else{
        w++;
        if(w>k){
            cout<<"NO"<<endl;
            flag=true;
            break;

        }
        }
        }
        if(!flag){
            cout<<"YES"<<endl;
        }
    }
}

