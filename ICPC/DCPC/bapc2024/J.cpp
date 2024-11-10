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
    bool valid=true;
    int a,b;
    a=0,b=0;
    forn(i,n){
        int d1,d2;
        cin>>d1>>d2;
        if(d1<a){
            valid=false;
        } else {
            a=d1;
        }

        if(d2<b){
            valid=false;
        } else {
            b=d2;
        }
    }

    if(valid)cout<<"yes";
    else cout<<"no";
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
