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
    forn(i,n){
        cin>>a[i];
    }
    for(int i=0;i<n-1;i++){
        if(2*a[i]>a[i+1] && 2*a[i+1]>a[i]){
            cout<<"YES"<<endl;
            return;
            
        }
    }
    reverse(a,a+n);
    for(int i=0;i<n-1;i++){
        if(2*a[i]>a[i+1] && 2*a[i+1]>a[i]){
            cout<<"YES"<<endl;
            return;
            
        }
    }
    cout<<"NO"<<endl;
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
