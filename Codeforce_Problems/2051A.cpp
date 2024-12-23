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
    int m=0;
    cin>>n;
    int a[n];
    int b[n];
    forn(i,n){
        cin>>a[i];
    }
    forn(i,n){
        cin>>b[i];
    }
    m+=a[n-1];
    for(int i=n-2;i>=0;i--){
        if(a[i]>b[i+1]){
            m+=(a[i]-b[i+1]);
        }
    }

    cout<<m<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
