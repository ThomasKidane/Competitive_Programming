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
    int n;
    cin>>n;
    int l,r;
    cin>>l>>r;
    int a[n];
    forn(i,n){
        cin>>a[i];
    }
    sort(a,a+l-1);
    // dbga(a,n);
    // dbgv(l);
    // reverse(a,a+l-1);
    // dbgv(r);
    sort(a+r,a+n);
    // reverse(a+r,a+n);
    sort(a+l-1,a+r);
    // reverse(a+l-1,a+r);
    // dbga(a,n);
    // dbgv(l)
    int v=r-l+1;
    ll S1=0;
    ll S2=0;
    int i=l-1;
    int c=r;
    // dbgv(r);
    
    forn(j,v){
        if(c<n){
            if(a[i]>a[c]){
                c++;
                S1+=a[c-1];
            } else {
                S1+=a[i];
                i++;
            }
        } else {
            S1+=a[i];
            i++;
        }
    }
    i=l-1;
    c=0;
    // dbgv(i);
    
    forn(j,v){
        if(c<l-1){
            if(a[i]>a[c]){
                c++;
                S2+=a[c-1];
            } else {
                S2+=a[i];
                i++;
            }
        } else {
            S2+=a[i];
            i++;
        }
    }

    cout<<min(S1,S2)<<endl;
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
