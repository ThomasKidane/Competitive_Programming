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
    string s;
    cin>>n>>s;
    int z=0;
    int o=0;
    forn(i,n){
        if(s[i]=='1')o++;
        else z++;
    }
    if(o>=z){cout<<"YES"<<endl;}
    else cout<<"NO"<<endl;

}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
