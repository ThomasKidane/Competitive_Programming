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

ll setBitNumber(ll n)
{
    if (n == 0)
        return 0;
 
    ll msb = 0;
    n = n / 2;
    while (n != 0) {
        n = n / 2;
        msb++;
    }
 
    return (1 << msb);
}
 

void solve(){
    ll x,m;
    cin>>x>>m;
    if(x>=m){
        // Brute Force
        int c=0;
        for(int i=1;i<=m;i++){
            if((i^x)%x==0 || (i^x)%i==0){
                c++;
            }
        }
        cout<<c<<endl;
    } else {
        // Get Lower half
        ll c=0;
        for(int i=1;i<=x;i++){
            if((i^x)%x==0 || (i^x)%i==0){
                c++;
            }
        }
        ll highestsetbit=setBitNumber(m);

        ll high=m;
        while(high>x){
            if((high^x)%x==0){
                break;
            } else{
                high--;
            }
        }
        ll low=x;
        while(low<m){
            if((low^x)%x==0 || (low^x)%low==0){
                break;
            } else{
                low++;
            }
        }
        // dbgv(high)

        cout<<c+max(0ll,(ll)ceil((ld(high-low)/x)))<<endl;
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
