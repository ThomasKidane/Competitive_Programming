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
    if(n%2==0){
        if(k%4==0){
            cout<<"YES"<<endl;
        } else if(k%4==3){
            cout<<"NO"<<endl;
        } else if(k%4==2){
            cout<<"NO"<<endl;
        } else if(k%4==1){
            cout<<"YES"<<endl;
        }
    } else {
        if(k%4==0){
            cout<<"YES"<<endl;
        }else if(k%4==3){
            cout<<"YES"<<endl;
        }else {
            cout<<"NO"<<endl;
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
