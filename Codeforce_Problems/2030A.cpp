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
    int b[n],c[n];
    forn(i,n){
        cin>>b[i];
        c[i]=b[i];
    }
    sort(b,b+n);
    sort(c,c+n);
    reverse(c,c+n);
    if(n>1){
        reverse(c+1,c+n);
    }
    
    int s=0;
    int M=c[0];
    int m=c[0];
    forn(i,n){
        M=max(M,c[i]);
        m=min(m,c[i]);
        s+=(M-m);
    }
    cout<<s<<endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
