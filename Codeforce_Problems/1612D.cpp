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
    ll a,b,x;
    cin>>a>>b>>x;
    // first right, and then left
    ll ca1,cb1,ca2,cb2;
    ca1=ca2=a;
    cb1=cb2=b;
    // First iteration
    bool f=false;
    while(cb1!=0 && ca1!=0 && !(cb1<x && ca1<x)){
        // if(f)
            if(cb1>ca1)swap(cb1,ca1);
            if(x%cb1==ca1%cb1){
                cout<<"YES"<<endl;
                return;
            } else {
                ca1=ca1%cb1;
            }
            // ca1=abs(ca1-cb1);
            // if(ca1==x || cb1==x){
            //     cout<<"YES"<<endl;
            //     return;
            // }
            // f=!f;
        // } 
    }
    // if(x%gcd(a,b)==0 && x<=max(a,b)){
    //    cout<<"YES"<<endl;
    //    return;
    // }
    cout<<"NO"<<endl;
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
