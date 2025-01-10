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
    ll b,n;
    cin>>b>>n;
    bool has=false;
    ll m=0;
   if(gcd(n,b)==1){
        bool f=false;
        bool s=false;//-1 first true, if 1 false
        ll ss=1;
        ll l=b%n;
        // dbgv(l);
        for(int i=0;i<n;i++){
            if(l==1 || l==n-1){
                // cout<<"here"<<endl;
                // dbgv(l);
                if(l==1){
                    // cout<<"a"<<endl;
                    s=false;
                } else {
                    s=true;
                }
                break;
            }
            l=(l*b)%n;
            ss+=1;
        }
        if(ss>n){
            cout<<0<<endl;
            return;
        }
        // dbgv(l);
        if(s){
            cout<<3<<' '<<ss<<endl;
        } else {
            cout<<2<<' '<<ss<<endl;
        }
    } else {
        ll ss=1;
        // int g=gcd(n,b);
        ll v=b%n;

        ll c=n+5;
        while(ss<c && v!=0){
            ss+=1;
            v*=(b%n);
            v%=n;
        }

        if(ss==c){
            cout<<0<<endl;
        } else {
            cout<<1<<' '<<ss<<endl;
        }
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
