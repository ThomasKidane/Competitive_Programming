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
    int x,y,k;
    cin>>x>>y>>k;
    int v=min(x,y);
    int m=max(x,y);
    int d=m-v;
    if(x>y){
        cout<<0<<' '<<0<<' '<<v<<' '<<v<<endl;
        cout<<v<<' '<<0<<' '<<0<<' '<<v<<endl;
    } else {
        cout<<0<<' '<<0<<' '<<v<<' '<<v<<endl;
        cout<<0<<' '<<v<<' '<<v<<' '<<0<<endl;
    }
    // int ax,ay,bx,by,cx,cy,dx,dy;
    
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
