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
    string s;
    cin>>s;
    int l=1;
    int r=(1<<n);
    int ll=0;
    int rr=0;
    forn(i,n){
        if(s[i]=='1'){
            l+=(1<<ll);
            ll++;
        } else {
            r-=(1<<rr);
            rr++;
        }
    }
    // dbgv(l);
    // dbgv(r);
    for(int i=l;i<=r;i++){
        cout<<i<<' ';
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
