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

ll maxand(ll a[],ll k,int n){
    // vector<ll> cost(n,0);
    
    vector<ll> anew(n);
    forn(i,n){
        anew[i]=a[i];
    }
    for(ll i=60;i>=0;i--){
        // make cost array
        // see if it can go, make new array
        // repeat to lsb
        ll c=0;
        bool nop=false;
        for(int j=0;j<n;j++){
            if(!((anew[j]>>i)&(1ll))){
                c+=((unsigned long long)(1ll<<i)-anew[j]%(1ll<<i));
                // dbgv((1ll<<i)-anew[j]%(1ll<<i));
                // cout<<"I << "<<(1<<i)<<endl;
                // dbgv(anew[j]%(1<<i));
                if(c>(1000000000000000000)){
                    nop=true;
                    break;
                }
            }
        }
        if(c<=k && !nop){
            //update array
            forn(j,n){
                if(!((anew[j]>>i)&(1ll))){
                    k-=((unsigned long long)(1ll<<i)-anew[j]%(1ll<<i));
                    anew[j]+=((unsigned long long)(1ll<<i)-anew[j]%(1ll<<i));                    
                }
        }
        }
        // dbgv(c);
        // dbgv(i);

    }

    ll res=(1ll<<62)-1;
    forn(j,n){
        res&=anew[j];
    }
    return res;
}

void solve(){
    int n,q;
    cin>>n>>q;
    ll a[n];
    forn(i,n){
        cin>>a[i];
    }

    forn(j,q){
        ll k;
        cin>>k;
        cout<<maxand(a,k,n)<<endl;
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
