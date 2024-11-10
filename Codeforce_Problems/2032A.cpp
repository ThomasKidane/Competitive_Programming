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
    int a[2*n];
    int v=0;
    forn(i,2*n){
        int d;        
        cin>>d;
        a[i]=d;
        v+=d;
    }
    if(v>=n){
        cout<<v%2<<' '<<(n-(v-n))<<endl;    
    } else {
        cout<<v%2<<' '<<v<<endl;    
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
