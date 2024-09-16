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
    int n,m,q;
    cin>>n>>m>>q;
    int p1,p2;
    cin>>p1>>p2;
    int p;
    cin>>p;
    if(p1>p2)swap(p1,p2);
    if(p<p1){cout<<p1-1<<endl;}
    else if(p>p2){cout<<n-p2<<endl;}
    else {
        cout<<(p2-p1)/2<<endl;
    }
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
