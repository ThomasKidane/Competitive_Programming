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
    int a[n];
    int mx;
    forn(i,n){
        cin>>a[i];
    }
    int mx1=a[0];
    int c1=0;
    for(int i=0;i<n;i+=2){
        if(mx1<a[i]){mx1=a[i];}
        c1++;
    }
    int mx2=a[0];
    int c2=0;
    
    if(n>1){
        mx2=a[1];
        for(int i=1;i<n;i+=2){
            if(mx2<a[i]){mx2=a[i];}
            c2++;
        }
    }
    cout<<max(mx1+c1,mx2+c2)<<endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
