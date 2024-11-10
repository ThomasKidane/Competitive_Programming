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
    // dbgv((int)ceil(double(k)/2));
    if(k>=2*(2*n-2)){
        // cout<<"ehre"<<endl;
        cout<<2*n-2+min(k-2*(2*n-2),2)<<endl;
    } else {
        cout<<(int)ceil(double(k)/2)<<endl;
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
