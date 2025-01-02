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
    ll l,r,g;
    cin>>l>>r>>g;
    if(l+((g-(l%g))%g)>r){
        cout<<-1<<' '<<-1<<endl;
        return;
    } else if(r-(r%g)<l){
        cout<<-1<<' '<<-1<<endl;
        return;
    } else {
        ll v11=l+((g-(l%g))%g);
        ll v22=r-(r%g);
        // dbgv(v2);
        // dbgv(gcd(v1,v2));
        if(gcd(v11,v22)==g){
            cout<<v11<<' '<<v22<<endl;
            return;
        } else {
            ll m1=v11;
            ll m2=v22;
            // dbgv((m1-m2)/(g));
            for(ll i=0;i<=min(120ll,(m2-m1)/(g));i++){
                ll v1=l+((g-(l%g))%g)+(i*g);
                // dbgv(v1);
                ll v2=r-(r%g);
                while(gcd(v1,v2)!=g && v2>=l-2*g) {
                    v2-=g;
                    // dbgv(gcd(v1,v2));
                }
                if(v2<l){
                    continue;
                } else {
                    if((gcd(m1,m2)!=g || abs(v2-v1)>abs(m1-m2))  && gcd(v1,v2)==g && v1<=r){
                        m1=v1;
                        m2=v2;
                        // break;
                    }
                }
            }
            // dbgv(m1);
            // dbgv(m2);
            for(ll i=0;i<=min(120ll,(m2-m1)/(g));i++){
                ll v1=l+((g-(l%g))%g);
                ll v2=r-(r%g)-(i*g);
                while(gcd(v1,v2)!=g && v1<=r+2*g) {
                    v1+=g;
                    // dbgv(gcd(v1,v2));
                }
                if(v1>r){
                    continue;
                } else {
                    if((gcd(m1,m2)!=g || abs(v2-v1)>abs(m1-m2)) && gcd(v2,v1)==g && v2>=l){
                        m1=v1;
                        m2=v2;
                        // break;
                    }
                }
            }
            if(gcd(m1,m2)==g && m1>=l && m1<=r && m2>=l && m2<=r){
                cout<<m1<<' '<<m2<<endl;
            } else {
                cout<<-1<<' '<<-1<<endl;
            }
            // while(gcd(v11,v22)!=g && v22>=l-2*g) {
            //     v22-=g;
            //     // dbgv(gcd(v1,v2));
            // }
            
            // if(v22<l && v1>r){
            //     cout<<-1<<' '<<-1<<endl;
            //     return;
            // } else {
            //     if(v22<l){
            //         cout<<v1<<' '<<v2<<endl;
            //         return;
            //     } else if(v1>r){
            //         cout<<v11<<' '<<v22<<endl;
            //         return;
            //     } else {
            //         if(abs(v22-v11)>=abs(v2-v1)){
            //             cout<<v11<<' '<<v22<<endl;
            //             return;
            //         } else {
            //             cout<<v1<<' '<<v2<<endl;
            //             return;
            //         }
            //     }
            // }
            // if(v2<l){
            //     cout<<-1<<' '<<-1<<endl;
            //     return;
            // } else {
            //     cout<<v1<<' '<<v2<<endl;
            //     return;
            // }
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
