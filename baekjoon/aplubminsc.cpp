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
    int a;
    int b;
    int c;
    cin>>a>>b>>c;
    cout<<a+b-c<<endl;
    cout<<a*max(10,int(pow(10,ceil(log(b))-1)))+b-c<<endl;
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
