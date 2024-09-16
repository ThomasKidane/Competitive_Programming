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
    if(n%4!=0 && n%4!=3)cout<<"NO";
    else {
        cout<<"YES"<<endl;
        if(n%4==3){
            cout<<n/2+1<<endl;
            for(int i=4;i<4+(n-3)/2;i+=2){
                cout<<i<<' ';
            }
            for(int i=n;i>=4+(n-3)/2;i-=2){
                cout<<i<<' ';
            }
            cout<<"2 1"<<endl;
            cout<<n/2<<endl;
            for(int i=5;i<4+(n-3)/2;i+=2){
                cout<<i<<' ';
            }
            for(int i=n-1;i>=4+(n-3)/2;i-=2){
                cout<<i<<' ';
            }
            cout<<"3"<<endl;
        }
        else {
            cout<<n/2<<endl;
            for(int i=1;i<n/2;i+=2){
                cout<<i<<' ';
            }
            for(int i=n;i>n/2;i-=2){
                cout<<i<<' ';
            }
            cout<<endl;
            cout<<n/2<<endl;
            for(int i=2;i<=n/2;i+=2){
                cout<<i<<' ';
            }
            for(int i=n-1;i>=n/2;i-=2){
                cout<<i<<' ';
            }
        }
    }
}

int main() {
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
