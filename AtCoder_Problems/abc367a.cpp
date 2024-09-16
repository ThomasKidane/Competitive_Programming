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
    int a,b,c;
    cin>>a>>b>>c;
    if(b<=c){
        if(a<b || a>c)cout<<"Yes";
        else cout<<"No";
    } else {
        if(a>=c && a<=b)cout<<"Yes";
        else cout<<"No";
    }
}

int main() {
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
