#include<bits/stdc++.h>

using ll = long long;
using ld = long double;
using namespace std;
// #define endl "\n";
#define ff first
#define ss second

#define forn(i,n) for(int i=0;i<n;i++)
#define dbgv(v) cout<<#v<<" "<<v<<endl
#define dbga(a,n) forn(i,n-1) {cout<<a[i]<<' ';} cout<<a[n-1]<<'\n';
int l=0;
int ss=0;


int ask(int i){
    cout<<"+ "<<i<<endl;
    ::ss+=i;
    int v;
    cin>>v;
    ::l=v;
    return v;
}

void solve(){
    int n;
    cin>>n;
    int s=0;
    // int l=0;
    int vv=0;
    int e=n/2;
    int v=pow(2,(int)ceil(log2(n)+0.00001))/2;
    for(int step=n/2;step<n,e>0;step=e,v/=2){
        // if(s+step<n){
        dbgv(v);
        if(s>=n-1 || v==0)break;
            if(ask(step)-vv){
                vv=l;
                
                s+=v;
                dbgv(vv);
                dbgv(e);
                dbgv(s);
                if(e!=1){
                    e/=2;
                    e+=n/2;
                    // (e==n)?e-=1:e;
                } else {
                    e=0;
                }
                
            }else {
                e/=2;
            }

        // }
    }

    cout<<"! "<<s+ss<<endl;
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
