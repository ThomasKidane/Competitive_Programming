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
    int n,k;
    cin>>n>>k;
    int a[n];
    cin>>a[0];
    int d=a[0];
    if(n>1){forn(i,n-1){cin>>a[i+1];d=gcd(a[i+1],d);}}   
    if(n==1){
        if(k>a[0]){cout<<k<<endl;}
        else cout<<k-1<<endl;
    }
    else if(d==1){cout<<(n-1+k)<<endl;}
    else {
        if(((k)/(d-1))<=(n-1)) {cout<<((k/(d-1)-1)*d+k%(d-1))+d+(k%(d-1)==0  ? -1 : 0) <<endl;}
        else {
            cout<<(n-1)*d+((k)-(d-1)*(n-1))<<endl;
        }
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
