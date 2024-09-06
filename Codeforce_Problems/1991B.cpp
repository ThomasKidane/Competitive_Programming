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
    int a[n-1];
    forn(i,n-1)cin>>a[i];
    int b[n];

    b[0]=a[0],b[n-1]=a[n-2];
    bool flag=false;
    forn(i,n-2){
        b[i+1]=a[i]|a[i+1];
        if(a[i]!=(a[i]|(b[i]&b[i+1]))){
            flag=true;
            break;
        }
    }
    if(flag){cout<<-1<<endl;return;}
    forn(i,n){
        cout<<b[i]<<' ';
    }
    cout<<endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}


