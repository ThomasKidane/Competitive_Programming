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
    int t[10000];
    int v[10000];
    t[0]=1;
    for(int i=1;i<10000;i++){
        if(i%2==0){
            t[i]=1+t[i-1];
        } else {
            t[i]=t[i-1];
        }
    }
    for(int i=0;i<10000;i++){
        if(i%2==0){
            v[i]=2*t[i]-1;
        } else {
            v[i]=2*t[i];
        }
    }

    if(n%2==1){
        cout<<2*v[(n+1)/2]*v[n/2]<<endl;
    } else {
        cout<<v[(n+1)/2]*v[n/2]<<endl;
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
