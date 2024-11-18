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
    ll n,b,c;
    cin>>n>>b>>c;
    if(b==0){
        if(n>c+2){
            cout<<-1<<endl;
        } else {
            if(c>=n){
                cout<<n<<endl;
            } else {
                cout<<n-1<<endl;
            }            
        }
    } else {
        if(c>=n){
            cout<<n<<endl;
        } else {
            cout<<n-(((n-1)-c)/b+1)<<endl;
        }
    }
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
