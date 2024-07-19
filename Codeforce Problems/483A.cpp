#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i,n) for(int i=0;i<n;i++)
#define dbgv(v) cout<<#v<<" "<<v<<'\n';
#define dbga(a,n) forn(i,n-1) {cout<<a[i]<<' ';} cout<<a[n-1]<<'\n';

signed main(){
    int l,r;
    cin>>l>>r;
    if(abs(r-l)<2) cout<<-1<<'\n';
    else{
        forn(i,(r-l)) {
            forn(x,(r-l)+1){
                forn(y,(r-l)+1){
                    if(__gcd(l+i,l+x)==1 && __gcd(l+y,l+x)==1 && l+i<l+x && l+x<l+y && l+y<=r && __gcd(l+i,l+y)!=1) {cout<<l+i<<" "<<l+x<<" "<<l+y;return 0;}
                }
            }
        }
        cout<<-1<<'\n';
    }

}


